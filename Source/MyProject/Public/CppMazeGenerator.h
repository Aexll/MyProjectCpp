// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "CppMazeGenerator.generated.h"

UCLASS()
class MYPROJECT_API ACppMazeGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppMazeGenerator();

    UFUNCTION(BlueprintCallable, Category = "MyClass")
    static TArray<int32> Generate2DArray(int32 SizeOfPlan);

private:
	static int32 GetRandomValue();

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UInstancedStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category = "Plan")
		int32 SizeOfPlan = 10;

	TArray<int32> MyArray;

	UFUNCTION()
		void PopulatePlan();

	TArray<int32> GenerateMaze(int32 MazeSize);

	void GenerateMazeRecursive(TArray<int32>& Maze, int32 MazeSize, int32 Row, int32 Col);

	TArray<int32> GenerateMaze_2(int32 mazesize);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
