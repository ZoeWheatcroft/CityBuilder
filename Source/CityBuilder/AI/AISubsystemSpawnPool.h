// Nap Time Studio

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BaseAICharacter.h"
#include "AISubsystemSpawnPool.generated.h"

USTRUCT()
struct FAIToSpawn {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABaseAICharacter> AIActor;

	UPROPERTY(EditAnywhere)
	int MaxAI;
};

/**
 * 
 */
UCLASS()
class CITYBUILDER_API UAISubsystemSpawnPool : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<FAIToSpawn> AIArray;
	
};
