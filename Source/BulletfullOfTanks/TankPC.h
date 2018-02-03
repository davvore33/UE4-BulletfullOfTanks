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
    void AimPlayerCrosshair();
    bool GetSightRayHitLocation(OUT FVector &HitLocation);

    UPROPERTY(EditAnywhere)
    float CrossHairXLocation = 0.5;
    UPROPERTY(EditAnywhere)
    float CrossHairYLocation = 0.5;
    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000;

    bool GetLookDirection(const FVector2D &ScreenLocation,
                              FVector &LookDirection) const;

	bool GetLookVectorHitLocation(const FVector &LookDirection,
								  OUT FVector &HitLocation) const;
};
