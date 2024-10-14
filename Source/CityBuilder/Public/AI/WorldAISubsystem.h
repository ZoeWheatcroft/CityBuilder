// Nap Time Studio

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Engine/World.h"
#include "UObject/Package.h"
#include "../AI/AISubsystemSpawnPool.h"
#include "../AI/BaseAICharacter.h"

#include "WorldAISubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CITYBUILDER_API UWorldAISubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	UAISubsystemSpawnPool* SpawnPoolData;
	
public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void OnWorldEndPlay(UWorld& InWorld);

public:
	//~FTickableGameObject implementation Begin
	virtual bool IsTickable() const override { return true; }
	virtual bool IsTickableInEditor() const override { return false; }
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;
	//~~FTickableGameObject implementation End

public:
	//~USubsystem implementation Begin
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//~~USubsystem implementation End

	UFUNCTION(BlueprintCallable)
	void SpawnCitizen();
};
