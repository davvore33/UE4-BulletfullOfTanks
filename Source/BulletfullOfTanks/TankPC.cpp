// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPC.h"

void ATankPC::BeginPlay() {
    auto pTank;

    Super::BeginPlay();

    pTank = GetControlledTank();

    if (!pTank) { //WARNING: Don't compare to `nullptr` otherwise crash
        UE_LOG(LogTemp, Warning, TEXT("%s: Got %s"), *pTank->GetName());
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
        // hit stuff
    }
}
