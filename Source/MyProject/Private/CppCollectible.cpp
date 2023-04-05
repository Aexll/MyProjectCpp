// Fill out your copyright notice in the Description page of Project Settings.


#include "CppCollectible.h"

// Sets default values
ACppCollectible::ACppCollectible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Collider
	SetActorEnableCollision(true);

	this->SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere collider"));
	this->SphereCollider->InitSphereRadius(50.0f);
	this->SphereCollider->SetGenerateOverlapEvents(true);
	this->SphereCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	
	this->SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACppCollectible::OnOverlapBegin);

	this->SphereCollider->SetupAttachment(RootComponent);
	RootComponent = SphereCollider;


	// mesh
	this->CollectibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin Mesh"));
	this->CollectibleMesh->SetupAttachment(RootComponent);
	this->CollectibleMesh->SetRelativeScale3D(FVector(0.4f, 0.4f, 0.4f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/Models/Coin.Coin"));

	if (CubeVisualAsset.Succeeded()) 
	{
		this->CollectibleMesh->SetStaticMesh(CubeVisualAsset.Object);
		this->CollectibleMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

}

// Called when the game starts or when spawned
void ACppCollectible::BeginPlay()
{
	Super::BeginPlay();

	UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material, this);

	FVector4 color(0.9,0.7,0.1,1);

	DynMaterial->SetVectorParameterValue("Color",color);
	CollectibleMesh->SetMaterial(0, DynMaterial);
	
}

// Called every frame
void ACppCollectible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CollectibleMesh->AddLocalRotation(FQuat(FVector(0,0,1),1 * DeltaTime));

}

void ACppCollectible::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CollectibleMesh->SetVisibility(false);
	CollectibleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

