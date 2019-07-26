// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CircleRotatingActor.generated.h"

UCLASS()
class FIRSTPERSONENV_API ACircleRotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACircleRotatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = Movement)
		float angleAxis;
	UPROPERTY(EditAnywhere, Category = Movement)
		float multiplier;
	UPROPERTY(EditAnywhere, Category = Movement)
		FVector dimensions;
	UPROPERTY(EditAnywhere, Category = Movement)
		FVector axisVector;
};
