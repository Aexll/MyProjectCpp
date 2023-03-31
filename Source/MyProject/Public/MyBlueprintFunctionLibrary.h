// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include <Kismet/GameplayStatics.h>
#include "Engine/World.h"
#include "MyActor.h"
#include "CppDoor.h"

#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Debug")
		static void Print(FString message);

	UFUNCTION(BlueprintCallable, Category = "Lightning")
		static void ToggleAllLights();

	UFUNCTION(BlueprintCallable, Category = "Testing")
		static int ReturnStuff(const FString intext, FString& return_string);

	UFUNCTION(BlueprintCallable, Category = "Doors")
		static void SetOpenDoorIndex(int index);

	UFUNCTION(BlueprintCallable, Category = "Doors")
		static void RandomiseAllDoorsIndexs();

};
