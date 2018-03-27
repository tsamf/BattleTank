// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	
	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No pawn is attached to the controller."))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is attached to the controller."), *ControlledTank->GetName())
	}

}


ATank* ATankAIController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}