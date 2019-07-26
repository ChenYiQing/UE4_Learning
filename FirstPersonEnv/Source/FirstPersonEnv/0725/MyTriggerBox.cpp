#define printf(myStr) 	if (GEngine)	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, myStr);
	

#include "MyTriggerBox.h"
#include "DrawDebugHelpers.h"


AMyTriggerBox::AMyTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this,&AMyTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapEnd);
}



void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Red, true, 100.f);
}

void AMyTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* otherActor)
{
	if (otherActor&&(otherActor!=this))
	{
		FString info = otherActor->GetName()+" enter the box";
		printf(info);
	}
}

void AMyTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* otherActor)
{
	if (otherActor && (otherActor != this))
	{
		FString info = otherActor->GetName() + " left the box";
		printf(info);
	}
}

