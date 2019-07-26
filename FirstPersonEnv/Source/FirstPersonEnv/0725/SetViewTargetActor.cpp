 // Fill out your copyright notice in the Description page of Project Settings.

#include "SetViewTargetActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASetViewTargetActor::ASetViewTargetActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASetViewTargetActor::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* ourPlayer = UGameplayStatics::GetPlayerController(this, 0);
	if (myActor!=nullptr)
	{
	//	ourPlayer->SetViewTarget(myActor);
		ourPlayer->SetViewTargetWithBlend(myActor, 4);
	}
}

// Called every frame
void ASetViewTargetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

