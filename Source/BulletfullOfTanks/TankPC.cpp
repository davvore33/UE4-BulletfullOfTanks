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

        if (GetSightRayHitLocation(OUT HitLocation)) {
            UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"),
                   *HitLocation.ToString());

        }
    }
}

bool ATankPC::GetSightRayHitLocation(OUT FVector &HitLocation) {
    int32 sizeX, sizeY;
    FVector2D ScreenLocation;
    FVector LookDirection;

    GetViewportSize(sizeX, sizeY);

    ScreenLocation = FVector2D(sizeX * CrossHairXLocation,
                               sizeY * CrossHairYLocation);

    if (GetLookDirection(ScreenLocation, LookDirection)) {
        GetLookVectorHitLocation(LookDirection, HitLocation);
    }

    return true;
}

bool ATankPC::GetLookDirection(const FVector2D &ScreenLocation,
                               FVector &LookDirection) const {
    FVector CameraLocation;

    if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y,
                                       CameraLocation, LookDirection)) {
//        UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"),
//               *LookDirection.ToString());
    }
    return true;
}

bool
ATankPC::GetLookVectorHitLocation(const FVector &LookDirection,
                                  OUT FVector &HitLocation) const {
    FVector Start, End;
    FHitResult hitResult;

    Start = PlayerCameraManager->GetCameraLocation();
    End = Start + (LookDirection * LineTraceRange);

    if (GetWorld()->LineTraceSingleByChannel(
            OUT hitResult,
            Start,
            End,
            ECollisionChannel::ECC_Visibility)) {
        HitLocation = hitResult.Location;

        return true;
    } else {
        return false;
    }
}
