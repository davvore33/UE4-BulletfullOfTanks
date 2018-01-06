// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPC.h"

void ATankPC::BeginPlay() {
    Super::BeginPlay();

    auto pTank = GetControlledTank();
    if (pTank != nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("%s: Got %s"), *pTank->GetName());
    } else {
        UE_LOG(LogTemp, Error, TEXT("%s: Got a NULL"));
    }

    UE_LOG(LogTemp, Warning, TEXT("%s: Begin Play"));
}

ATank *ATankPC::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}
