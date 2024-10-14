// Nap Time Studio

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Engine/World.h"
#include "UObject/Package.h"
#include "WorldManagerSubsystem.generated.h"

UENUM(BlueprintType)
enum class EPlayerGameMode : uint8 {
	Play, 
	Build
};

DECLARE_MULTICAST_DELEGATE(FPlayerGameModeChanged);

/**
 * 
 */
UCLASS()
class CITYBUILDER_API UWorldManagerSubsystem : public UTickableWorldSubsystem
{

	GENERATED_BODY()

private:
	// world variables
	int Citizens = 0;
	float Money = 0;


public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void OnWorldEndPlay(UWorld& InWorld);

	UPROPERTY(BlueprintReadOnly)
	EPlayerGameMode PlayerGameMode;

public:
	//~FTickableGameObject implementation Begin
	virtual bool IsTickable() const override { return true; }
	virtual bool IsTickableInEditor() const override { return false; }
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;
	//~~FTickableGameObject implementation End
	//~USubsystem implementation Begin
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//~~USubsystem implementation End
	UFUNCTION(BlueprintCallable)
	void SwitchPlayerGameMode(EPlayerGameMode newMode, AActor* instigator);

	UFUNCTION(BlueprintCallable)
	int GetCitizenCount();
	
	UFUNCTION(BlueprintCallable)
	float GetMoney();	
	
	UFUNCTION(BlueprintCallable)
	bool SetCitizenCount(int newCount);
	
	UFUNCTION(BlueprintCallable)
	bool SetMoney(float newMoney);

	FPlayerGameModeChanged PlayerGameModeChangedDelegate;

	
};
