// Fill out your copyright notice in the Description page of Project Settings.

#include "PillSpawner.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"
// Sets default values
APillSpawner::APillSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spawningVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolumeBox"));
	
}


// Called when the game starts or when spawned
void APillSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APillSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector APillSpawner::GetRandomPointInVolume()
{
	FVector origin = spawningVolume->Bounds.Origin;
	FVector extent = spawningVolume->Bounds.BoxExtent;
	return UKismetMathLibrary::RandomPointInBoundingBox(origin, extent);
}

void APillSpawner::SpawnPill()
{
	if (itemToSpawn!=nullptr)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			FVector spawnLoc = GetRandomPointInVolume();
			FRotator spawnRot;
			spawnRot.Pitch = FMath::FRand()*360.f;
			spawnRot.Roll = FMath::FRand()*360.f;
			spawnRot.Yaw = FMath::FRand()*360.f;
			AMyMagicPill* spawnPill = World->SpawnActor<AMyMagicPill>(itemToSpawn,spawnLoc,spawnRot);
		}
	}
}

