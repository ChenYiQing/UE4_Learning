// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MyTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSONENV_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
	AMyTriggerBox();


protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	    void OnOverlapBegin(class AActor* OverlappedActor,class AActor* otherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* otherActor);



	UPROPERTY(EditAnywhere)
		class AActor* specificActor;
		
};
