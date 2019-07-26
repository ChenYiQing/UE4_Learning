// Fill out your copyright notice in the Description page of Project Settings.

#include "CircleRotatingActor.h"


// Sets default values
ACircleRotatingActor::ACircleRotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACircleRotatingActor::BeginPlay()
{
	Super::BeginPlay();

	dimensions = FVector(0, 300, 0);
	axisVector = FVector(0,0,1);
	multiplier = 50.f;
}

// Called every frame
void ACircleRotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = FVector(0,0,800);

	angleAxis += DeltaTime * multiplier;
	if (angleAxis>=360)
	{
		angleAxis = 0;
	}
	FVector rotateValue = dimensions.RotateAngleAxis(angleAxis, axisVector);

	newLocation += rotateValue;
	SetActorLocation(newLocation, false, 0, ETeleportType::None);

}

