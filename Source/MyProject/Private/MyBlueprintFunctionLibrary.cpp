// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::Print(FString message)
{
#if UE_EDITOR
	GEngine->AddOnScreenDebugMessage(-10, 15.0f, FColor::Red, message);
#endif
	UE_LOG(LogTemp, Log, TEXT("%s"), *message);
}

void UMyBlueprintFunctionLibrary::ToggleAllLights()
{
	Print("[LIGHTS] will switch all ligts...");
	UWorld* world = GEngine->GameViewport->GetWorld();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(
		world,
		AMyActor::StaticClass(),
		Actors
	);

	for (AActor* tmpActor : Actors)
	{
		((AMyActor*)tmpActor)->ToggleLight();
	}
}

int UMyBlueprintFunctionLibrary::ReturnStuff(const FString intext, FString& return_string)
{
	return_string = intext;
	return 42;
}
