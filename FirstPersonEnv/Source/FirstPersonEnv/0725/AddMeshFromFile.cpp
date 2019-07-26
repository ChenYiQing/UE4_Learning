// Fill out your copyright notice in the Description page of Project Settings.

#include "AddMeshFromFile.h"
#include "ConstructorHelpers.h"

// Sets default values
AAddMeshFromFile::AAddMeshFromFile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	UStaticMeshComponent* myCylinder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Cylinder"));
	myCylinder->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> myCylinderAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));

	if (myCylinderAsset.Succeeded())
	{
		myCylinder->SetStaticMesh(myCylinderAsset.Object);
		myCylinder->SetRelativeLocation(FVector(0,0,0));
		myCylinder->SetWorldScale3D(FVector(1.f));
	}
}

// Called when the game starts or when spawned
void AAddMeshFromFile::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AAddMeshFromFile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

