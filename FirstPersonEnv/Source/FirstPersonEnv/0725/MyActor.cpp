// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT(text));
#include "MyActor.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyBillboardComp = CreateDefaultSubobject<UBillboardComponent>(TEXT("My Billboard"));
	MyBillboardComp->SetHiddenInGame(false,true);
	RootComponent = MyBillboardComp;


	myStaticMeshCom = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My StaticMeshCom"));



}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();


	UE_LOG(LogTemp, Warning, TEXT("go......"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("screen info"));
	}
	print("print by define");



	int32 myInt = 123;
	FString myStr = "my string info";
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,myStr);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(myInt));
	}


	int32 numPawns = GetWorld()->GetNumPawns();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(numPawns));
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector playerLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *playerLoc.ToString());
	}
}


