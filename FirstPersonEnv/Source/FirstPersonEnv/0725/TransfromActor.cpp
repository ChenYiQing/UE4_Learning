// Fill out your copyright notice in the Description page of Project Settings.

#include "TransfromActor.h"


// Sets default values
ATransfromActor::ATransfromActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATransfromActor::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocationAndRotation(newLocation, newRotation, false, 0, ETeleportType::None);

}

// Called every frame
void ATransfromActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

