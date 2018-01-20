// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPC.generated.h" //Must be the very last include

/**
 * Tank Player Controller class
 */
UCLASS()
class BULLETFULLOFTANKS_API ATankPC : public APlayerController
{
	GENERATED_BODY()

public:
    ATank* GetControlledTank() const;

    virtual void Tick(float) override;
    virtual void BeginPlay() override;

private:
    bool GetSightRayHitLocation(OUT FVector &HitLocation);
    void AimPlayerCrosshair();
};
