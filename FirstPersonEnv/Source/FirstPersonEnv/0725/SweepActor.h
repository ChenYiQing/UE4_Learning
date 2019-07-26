// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SweepActor.generated.h"

UCLASS()
class FIRSTPERSONENV_API ASweepActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASweepActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, Category = "Locations")
		FVector locOne;
	UPROPERTY(EditAnywhere, Category = "Locations")
		FVector locTwo;
	UPROPERTY(EditAnywhere, Category = "Locations")
		FVector locThree;
	UPROPERTY(EditAnywhere, Category = "Locations")
		FVector locFour;
	UPROPERTY(EditAnywhere, Category = "Locations")
		FVector locFive;

	UPROPERTY(EditAnywhere, Category = "Locations")
		FBox  myBox;
	UPROPERTY(EditAnywhere, Category = "Locations")
		FTransform myTransfrom;
};
