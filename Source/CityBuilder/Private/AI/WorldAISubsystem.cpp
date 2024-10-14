// Nap Time Studio


#include "AI/WorldAISubsystem.h"

void UWorldAISubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	//create pool of citizens
	FString Path = TEXT("/CityBuilder/Content/AI/Data/DA_AISubsystemSpawnPool.uasset");
	if (FPaths::FileExists(Path))
	{
		SpawnPoolData = Cast<UAISubsystemSpawnPool>(LoadObject<UAISubsystemSpawnPool>(nullptr, *Path));
	}
	if (SpawnPoolData)
	{
		for (int i = 0; i < SpawnPoolData->AIArray.Num(); i++)
		{
			FAIToSpawn AIToSpawn = SpawnPoolData->AIArray[i];
			for (int j = 0; j < AIToSpawn.MaxAI; j++)
			{
				FTransform Transform = FTransform();
				Transform.SetLocation(FVector(-1000, -1000, -1000));

				FActorSpawnParameters ActorSpawnParameters;

				GetWorld()->SpawnActor<ABaseAICharacter>(AIToSpawn.AIActor, FVector::ZeroVector, FRotator::ZeroRotator);
			}
		}
	}

}

void UWorldAISubsystem::OnWorldEndPlay(UWorld& InWorld)
{

}

void UWorldAISubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TStatId UWorldAISubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UWorldManagerSubsystem, STATGROUP_Tickables);
}

void UWorldAISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UWorldAISubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UWorldAISubsystem::SpawnCitizen()
{
}
