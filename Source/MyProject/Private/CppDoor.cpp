// Fill out your copyright notice in the Description page of Project Settings.


#include "CppDoor.h"

// Sets default values
ACppDoor::ACppDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/Models/Door.Door"));

	if (CubeVisualAsset.Succeeded()) 
	{
		DoorMesh->SetStaticMesh(CubeVisualAsset.Object);
		DoorMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void ACppDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppDoor::SetDoorOpen(bool isOpened)
{
	DoorMesh->SetVisibility(!isOpened, true);
	DoorMesh->SetCollisionResponseToAllChannels(isOpened ? ECollisionResponse::ECR_Ignore : ECollisionResponse::ECR_Block);
}

void ACppDoor::OpenDoorIndex(int index)
{
	SetDoorOpen(index == DoorIndex);
}

void ACppDoor::RandomiseIndex()
{
	DoorIndex = FMath::RandRange(0,3);

	FVector4 color(0.9,0.7,0.1,1);

	switch (DoorIndex)
	{
	case 0:
		color = FVector4(1,0,0,1);
		break;
	case 1:
		color = FVector4(0,1,0,1);
		break;
	case 2:
		color = FVector4(0,0,1,1);
		break;
	case 3:
		color = FVector4(1,1,0,1);
		break;
	default:
		break;
	}

	UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(DoorMaterial, this);


	DynMaterial->SetVectorParameterValue("Color",color);
	DoorMesh->SetMaterial(0, DynMaterial);
}


