// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/SphereComponent.h"

#include "CppCollectible.generated.h"

UCLASS()
class MYPROJECT_API ACppCollectible : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppCollectible();
	UPROPERTY(VisibleAnywhere, Category = "Collectible")
		USphereComponent* SphereCollider;


	UPROPERTY(VisibleAnywhere);
		UStaticMeshComponent* CollectibleMesh;

	UPROPERTY(EditAnywhere, Category = "Material")
		UMaterialInterface* Material;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlapBegin(
			class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult
		);


};
