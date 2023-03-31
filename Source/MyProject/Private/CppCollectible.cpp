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
	this->SphereCollider->InitSphereRadius(300.0f);
	this->SphereCollider->SetGenerateOverlapEvents(true);
	this->SphereCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	
	this->SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACppCollectible::OnOverlapBegin);

	this->SphereCollider->SetupAttachment(RootComponent);


	// mesh
	CollectibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	//CollectibleMesh->SetupAttachment(SphereCollider);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/Models/Door.Door"));

	if (CubeVisualAsset.Succeeded()) 
	{
		CollectibleMesh->SetStaticMesh(CubeVisualAsset.Object);
		CollectibleMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

}

// Called when the game starts or when spawned
void ACppCollectible::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppCollectible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppCollectible::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CollectibleMesh->SetVisibility(false);
}

