// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppDoor.generated.h"

UCLASS()
class MYPROJECT_API ACppDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppDoor();

	UPROPERTY(EditAnywhere,BlueprintReadWrite);
		int DoorIndex;

	UPROPERTY(VisibleAnywhere);
		UStaticMeshComponent* DoorMesh;


	UPROPERTY(EditAnywhere, Category = "Material")
		UMaterialInterface* DoorMaterial;


	//UStaticMeshComponent

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void SetDoorOpen(bool isOpened);


	UFUNCTION(BlueprintCallable)
		void OpenDoorIndex(int index);

	UFUNCTION(BlueprintCallable)
		void RandomiseIndex();


};
