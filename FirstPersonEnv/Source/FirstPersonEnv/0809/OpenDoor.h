// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRSTPERSONENV_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere)
		float openAngle = 0.0f;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* pressurePlate;
	UPROPERTY()
		AActor* actorThatOpens;

	UPROPERTY(EditAnywhere)
		float doorCloseDelay = 1.0f;
	
	float lastDoorOpenTime;


	void OpenDoor();
	void CloseDoor();
};
