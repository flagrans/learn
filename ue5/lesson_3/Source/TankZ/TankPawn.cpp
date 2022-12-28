// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "TankPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/ArrowComponent.h"
#include "Cannon.h"

ATankPawn::ATankPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    RootComponent = BoxCollision;

    BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
    BodyMesh->SetupAttachment(BoxCollision);

    TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
    TurretMesh->SetupAttachment(BodyMesh);

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(BoxCollision);
    SpringArm->bDoCollisionTest = false;
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritRoll = false;
    SpringArm->bInheritYaw = false;

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

    CannonSetupPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("CannonSetupPoint"));
    CannonSetupPoint->SetupAttachment(TurretMesh);
}

void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
    
    Move(DeltaTime);


    float yawRotation = RotationSpeed * targetRotateRightAxisValue * DeltaTime;
    FRotator currentRotation = GetActorRotation();
    yawRotation += currentRotation.Yaw;
    FRotator newRotation = FRotator(0.0f, yawRotation, 0.0f);
    SetActorRotation(newRotation);


    if (TankController) 
    {
      FVector mousePos = TankController->GetMousePosition();
      FRotator targetRotation =
          UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), mousePos);
      FRotator TurretRotation = TurretMesh->GetComponentRotation();
      targetRotation.Pitch = TurretRotation.Pitch;
      targetRotation.Roll = TurretRotation.Roll;
      TurretMesh->SetWorldRotation(FMath::Lerp(TurretRotation, targetRotation, TurretRotationInterpolationKey));
    }

}

void ATankPawn::Move(float DeltaTime) {

    FVector CurrentPosition = GetActorLocation();
    FVector ForwardVector = GetActorForwardVector();
    FVector RightVector = GetActorRightVector();
    FVector movePosition =
        CurrentPosition +
        ForwardVector * MoveSpeed * targetForwardAxisValue * DeltaTime +
        RightVector * MoveSpeed * targetRightAxisValue * DeltaTime;

    SetActorLocation(movePosition, true);
}

void ATankPawn::MoveForward(float Value)
{ 
    targetForwardAxisValue = Value;
}

void ATankPawn::MoveRight(float Value) 
{ 
    targetRightAxisValue = Value; 
}

void ATankPawn::Fire() {
    if (Cannon)
    {
      Cannon->Fire();
    }
}

void ATankPawn::FireSpecial() {
    if (Cannon) {
      Cannon->FireSpecial();
    }
}

void ATankPawn::SetupCannon(TSubclassOf<ACannon> newCannonClass) {
    if (!newCannonClass)
    {
      return;
    }
    if (Cannon)
    {
      Cannon->Destroy();

    }
    FActorSpawnParameters spawnParams;
    spawnParams.Instigator = this;
    spawnParams.Owner = this;

    Cannon = GetWorld()->SpawnActor<ACannon>(newCannonClass, spawnParams);
    Cannon->AttachToComponent(
        CannonSetupPoint,
        FAttachmentTransformRules::SnapToTargetNotIncludingScale);

}

void ATankPawn::BeginPlay() 
{ 
    Super::BeginPlay();
    TankController = Cast<ATankPlayerController>(GetController());
    SetupCannon(CannonClass);
}

void ATankPawn::RotateRight(float Value) 
{ 
    targetRotateRightAxisValue = Value;
}
