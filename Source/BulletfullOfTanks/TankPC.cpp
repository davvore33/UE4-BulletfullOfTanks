// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPC.h"

ATank* ATankPC::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}
