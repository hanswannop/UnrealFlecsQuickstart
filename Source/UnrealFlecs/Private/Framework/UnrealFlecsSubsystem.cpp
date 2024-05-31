﻿// Copyright 2021 Red J
#include "Framework/UnrealFlecsSubsystem.h"
#include "Containers/Ticker.h"
#include "Framework/FlecsRegistration.h"


void UUnrealFlecsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	OnTickDelegate = FTickerDelegate::CreateUObject(this, &UUnrealFlecsSubsystem::Tick);
	OnTickHandle = FTSTicker::GetCoreTicker().AddTicker(OnTickDelegate);

	ECSWorld = new flecs::world();

	auto& regs = FlecsRegContainer::GetFlecsRegs();
    for (auto reg : regs)
    {
    	reg(*ECSWorld);
    }
	UE_LOG(LogTemp, Warning, TEXT("Total Component Registrations %s"), *FString::FromInt(regs.Num()));
	
	UE_LOG(LogTemp, Warning, TEXT("UUnrealFlecsSubsystem has started!"));
	
	Super::Initialize(Collection);
}

void UUnrealFlecsSubsystem::Deinitialize()
{
	FTSTicker::GetCoreTicker().RemoveTicker(OnTickHandle);

	if(ECSWorld)
	{
		delete(ECSWorld);
	}

	UE_LOG(LogTemp, Warning, TEXT("UUnrealFlecsSubsystem has shut down!"));
	
	Super::Deinitialize();
}

flecs::world* UUnrealFlecsSubsystem::GetEcsWorld() const
{
	return ECSWorld;
}

bool UUnrealFlecsSubsystem::Tick(float DeltaTime)
{
	if(ECSWorld) ECSWorld->progress(DeltaTime);

	return true;
}
