// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIC.generated.h"

/**
 * 
 */
UCLASS()
class BULLETFULLOFTANKS_API ATankAIC : public AAIController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	virtual void Tick(float) override;
	virtual void BeginPlay() override;

private:

	ATank* GetPlayerTank() const;

};
