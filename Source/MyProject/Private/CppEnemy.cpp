// Fill out your copyright notice in the Description page of Project Settings.


#include "CppEnemy.h"

// Sets default values
ACppEnemy::ACppEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACppEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<FVector> Directions = {
		FVector(1,0,0),
		FVector(0,1,0),
		FVector(-1,0,0),
		FVector(0,-1,0),
	};

	FVector selectedDirection = Directions[FMath::RandRange(0, Directions.Num() - 1)];

	AddMovementInput(selectedDirection, 1);

}

// Called to bind functionality to input
void ACppEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

