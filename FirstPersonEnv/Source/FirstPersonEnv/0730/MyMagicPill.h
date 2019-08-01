// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "MyMagicPill.generated.h"


DECLARE_LOG_CATEGORY_CLASS(AMyMagicPillLog, Log, All);

UCLASS()
class FIRSTPERSONENV_API AMyMagicPill : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyMagicPill();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		int32 abc;
	UPROPERTY(BlueprintReadWrite)
		int32 aa;
	


	UFUNCTION(BlueprintCallable)
		void myFun();

		UStaticMeshComponent* pillMesh;

};
