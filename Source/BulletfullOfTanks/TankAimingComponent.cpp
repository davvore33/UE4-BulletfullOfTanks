// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() {
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay() {
    Super::BeginPlay();

    // ...

}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction *ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
    auto StartLocation = Head->GetSocketLocation(FName("FiringHole"));
    auto EndLocation = HitLocation;
    auto TossSpeed = LaunchSpeed;
    FVector TossVelocity;

    // Calculate Toss Velocity
    if (UGameplayStatics::SuggestProjectileVelocity(this, OUT TossVelocity,
                                                    StartLocation,
                                                    EndLocation,
                                                    TossSpeed, false, 0, 0,
                                                    ESuggestProjVelocityTraceOption::DoNotTrace)) {

        auto AimDirection = TossVelocity.GetSafeNormal();

        UE_LOG(LogTemp, Warning, TEXT("Firing at %s"),
               *AimDirection.ToString());
    }
}

void UTankAimingComponent::SetHead(UStaticMeshComponent *Head) {
    UTankAimingComponent::Head = Head;
}

UStaticMeshComponent *UTankAimingComponent::GetHead() const {
    return Head;
}
