// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	
	if(!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not find player"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is the player."), *PlayerTank->GetName())
	}


	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No pawn is attached to the controller."))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is attached to the controller."), *ControlledTank->GetName())
	}

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}