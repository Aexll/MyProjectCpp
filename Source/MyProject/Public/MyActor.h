// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/PointLightComponent.h"

#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere, Category = "Custom light")
		float Intensity;

	UPROPERTY(EditAnywhere, Category = "Custom light")
		bool IsVisibleStart;

	UPROPERTY(VisibleAnywhere, Category = "Custom light")
		UPointLightComponent* PointLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,Category = "Custom light")
		void ToggleLight();

};
