// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT(text))
#include "MyMagicPill.h"
#include "ConstructorHelpers.h"

// Sets default values
AMyMagicPill::AMyMagicPill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pillMesh = CreateDefaultSubobject<UStaticMeshComponent>("MyCom");
	auto meshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));
   if (meshAsset.Object!=nullptr)
   {
	   pillMesh->SetStaticMesh(meshAsset.Object);

   }
}

// Called when the game starts or when spawned
void AMyMagicPill::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(AMyMagicPillLog, Log, TEXT("go ****************************"));

	if (pillMesh!=nullptr)
	{
		pillMesh->SetSimulatePhysics(true);
		printf("not null");
		UE_LOG(AMyMagicPillLog, Log, TEXT("not nullptr ****************************"));
	}
	else
	{
		UE_LOG(AMyMagicPillLog, Log, TEXT("nullptr ****************************"));
		printf("null");
	}

}

// Called every frame
void AMyMagicPill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyMagicPill::myFun()
{

}

