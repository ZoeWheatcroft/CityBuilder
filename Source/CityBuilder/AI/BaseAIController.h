// Nap Time Studio

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

class UBehaviorTree;

/**
 * 
 */
UCLASS()
class CITYBUILDER_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadWrite, Category="AI")
	UBehaviorTree* BehaviorTree;

	virtual void BeginPlay() override;
	
};
