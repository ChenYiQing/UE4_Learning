// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "MyMagicPill.h"
#include "PillSpawner.generated.h"

UCLASS()
class FIRSTPERSONENV_API APillSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APillSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category = "Spawning")
		TSubclassOf<class AMyMagicPill> itemToSpawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
		 UBoxComponent* spawningVolume;

	FVector GetRandomPointInVolume();

	UFUNCTION(BlueprintCallable)
		void SpawnPill();

};
