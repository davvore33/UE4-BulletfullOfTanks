// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIC.h"

void ATankAIC::BeginPlay() {
    ATank *pTank;

    Super::BeginPlay();

    pTank = GetControlledTank();

    if (IsValid(pTank)) { //WARNING: Don't compare to `nullptr` otherwise crash
        UE_LOG(LogTemp, Warning, TEXT("Got %s"), *pTank->GetName());
    } else {
        UE_LOG(LogTemp, Error, TEXT("Got a NULL"));
    }

}

void ATankAIC::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    if(GetPlayerTank()) {
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
    } else {
        //false act
    }
}

ATank *ATankAIC::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIC::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerPawn) { return nullptr; } // Note the !, very important
    return Cast<ATank>(PlayerPawn);
}