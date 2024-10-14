// Nap Time Studio


#include "WorldManagerSubsystem.h"
#include "Logging/LogMacros.h" 

void UWorldManagerSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	LoadObject<UMaterial>(nullptr, TEXT("/Game/Map/Materials/grass.grass"));
}

void UWorldManagerSubsystem::OnWorldEndPlay(UWorld& InWorld)
{

}

void UWorldManagerSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TStatId UWorldManagerSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UWorldManagerSubsystem, STATGROUP_Tickables);
}

void UWorldManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWorldManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UWorldManagerSubsystem::SwitchPlayerGameMode(EPlayerGameMode newMode, AActor* instigator)
{
	//TODO -- give world manager its own log
	//UE_LOG(LogTemp, Log, TEXT(“game mode switched to %d by %s”), newMode, instigator->GetDebugName());
	//UE_LOG(LogTemp, Log, TEXT(“switching game mode));
	PlayerGameMode = newMode;
	PlayerGameModeChangedDelegate.Broadcast();
}

int UWorldManagerSubsystem::GetCitizenCount()
{
	return Citizens;
}

float UWorldManagerSubsystem::GetMoney()
{
	return Money;
}

bool UWorldManagerSubsystem::SetCitizenCount(int newCount)
{
	Citizens = newCount;
	return true;
}

bool UWorldManagerSubsystem::SetMoney(float newMoney)
{
	Money = newMoney;
	return false;
}
