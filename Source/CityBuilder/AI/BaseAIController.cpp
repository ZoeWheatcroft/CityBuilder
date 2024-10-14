// Nap Time Studio


#include "BaseAIController.h"

void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);

	FVector randomTarget = FMath::VRand();

	
}
