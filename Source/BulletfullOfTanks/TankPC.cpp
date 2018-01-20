// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPC.h"

void ATankPC::BeginPlay() {
    ATank *pTank;

    Super::BeginPlay();

    pTank = GetControlledTank();

    if (IsValid(pTank)) { //WARNING: Don't compare to `nullptr` otherwise crash
        UE_LOG(LogTemp, Warning, TEXT("Got %s"), *pTank->GetName());
    } else {
        UE_LOG(LogTemp, Error, TEXT("Got a NULL"));
    }

    UE_LOG(LogTemp, Warning, TEXT("Begin Play"));
}

void ATankPC::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    AimPlayerCrosshair();
}

ATank *ATankPC::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

void ATankPC::AimPlayerCrosshair() {
    if (GetControlledTank()) {
        FVector HitLocation;

        if (GetSightRayHitLocation(OUT HitLocation)) UE_LOG(LogTemp, Warning,
                                                            TEXT("Hit Location: %s"),
                                                            *HitLocation.ToString());

        // hit stuff
    }
}

bool ATankPC::GetSightRayHitLocation(OUT FVector &HitLocation) {
    HitLocation = FVector(1.0);
    return true;
}
