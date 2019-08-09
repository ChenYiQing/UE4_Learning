// Fill out your copyright notice in the Description page of Project Settings.

#include "GrabberCom.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UGrabberCom::UGrabberCom()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabberCom::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabberCom::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//viewport 
	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(playerViewPointLocation,playerViewPointRotation);
	//linetrace

	FVector lineTraceEnd = playerViewPointLocation + playerViewPointRotation.Vector()*reach;


	DrawDebugLine(
		GetWorld(),
		playerViewPointLocation,
		lineTraceEnd,
		FColor::Red,
		false,
		0.f,
		0.f,
		10.f
	);

	FCollisionQueryParams traceParameters(FName(TEXT("")),false,GetOwner());
	FHitResult hit;
	GetWorld()->LineTraceSingleByObjectType(
		hit,
		playerViewPointLocation,
		lineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		traceParameters
	);

	AActor* actorHit = hit.GetActor();
	if (actorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("LineTrace hit actor : %s"), *actorHit->GetFName().ToString());
	}

	//get hit

}

