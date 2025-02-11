// Fill out your copyright notice in the Description page of Project Settings.

#include "SweepActor.h"
#include "DrawDebugHelpers.h"

// Sets default values
ASweepActor::ASweepActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	locOne = FVector(0,0,600);
	locTwo = FVector(0, -600, 600);
	locThree = FVector(0, 600, 600);
	locFour = FVector(-300, 0, 600);
	locFive = FVector(-400, 600, 600);

	myBox = FBox(FVector(0,0,0),FVector(100,100,100));
	myTransfrom.SetLocation(FVector(200,500,600));

}

// Called when the game starts or when spawned
void ASweepActor::BeginPlay()
{
	Super::BeginPlay();
	

	//DrawDebugPoint(GetWorld(),locOne,200,FColor(52,200,249),true,100.f);
	//DrawDebugSphere(GetWorld(), locTwo, 600, 60, FColor(181, 0, 0), true, 100.f, 0, 8);
	//DrawDebugCircle(GetWorld(), locThree, 200, 50, FColor(0, 0, 0), true, 100.f, 0, 8);
	//DrawDebugSolidBox(GetWorld(), myBox, FColor(20, 100,240), myTransfrom, true,100.f);
	//DrawDebugBox(GetWorld(), locFive, FVector(500, 500, 500), FColor::Red, true, 100.f);
	//DrawDebugLine(GetWorld(), locTwo, locThree,FColor::Green,true,100.f);
	//DrawDebugDirectionalArrow(GetWorld(),FVector(-300,600,600),FVector(-300,-600,600),120.f,FColor::Blue,true,100.f);
	//DrawDebugCrosshairs(GetWorld(),FVector(0,0,1000),FRotator(0,0,0),500.f,FColor::White,true,100.f);

	CallSweepMutiLineTrace();


}

// Called every frame
void ASweepActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASweepActor::CallSweepMutiLineTrace()
{
	TArray<FHitResult> OutHits;
	FVector myLoc = GetActorLocation();

	FCollisionShape myColSphere = FCollisionShape::MakeSphere(500.f);
	DrawDebugSphere(GetWorld(), myLoc, myColSphere.GetSphereRadius(), 50, FColor::Blue, true,100.f);

	bool isHit = GetWorld()->SweepMultiByChannel(OutHits, myLoc, myLoc, FQuat::Identity, ECC_WorldStatic, myColSphere);
	if (isHit)
	{
		for (auto& Hit:OutHits)
		{
			UStaticMeshComponent* meshCom = Cast<UStaticMeshComponent>((Hit.GetActor())->GetRootComponent());
			if (meshCom)
			{
				meshCom->AddRadialImpulse(myLoc, 500.f, 2000.f, ERadialImpulseFalloff::RIF_Constant, true);
			}
		}
	}
}

void ASweepActor::CallLineTranceSingle()
{
	FHitResult OutHit;

	FVector start = FVector(0, 0, 200);
	FVector forwardVector = GetActorForwardVector();
	FVector end = (start + (forwardVector*10000.f));

	FCollisionQueryParams collisionParams;

	DrawDebugLine(GetWorld(),start,end,FColor::Green,true,100.f);
	bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, start, end, ECC_WorldStatic, collisionParams);

	if (isHit)
	{
		if (OutHit.bBlockingHit)
		{
			if (GEngine)
			{
				FString hitStr = "Hit Struff is " + OutHit.GetActor()->GetName();
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, hitStr);
			}
		}
	}
}

