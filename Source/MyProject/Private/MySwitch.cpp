// Fill out your copyright notice in the Description page of Project Settings.


#include "MySwitch.h"

// Sets default values
AMySwitch::AMySwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetActorEnableCollision(true);

	this->SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere collider"));
	this->SphereCollider->InitSphereRadius(300.0f);
	this->SphereCollider->SetGenerateOverlapEvents(true);
	this->SphereCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	
	this->SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &AMySwitch::OnOverlapBegin);

	this->SphereCollider->SetupAttachment(RootComponent);
}


// Called when the game starts or when spawned
void AMySwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMySwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMySwitch::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UMyBlueprintFunctionLibrary::Print("ptn");
	UMyBlueprintFunctionLibrary::ToggleAllLights();
	
}

