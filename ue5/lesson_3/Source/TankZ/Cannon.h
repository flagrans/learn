// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameStructs.h"
#include "Cannon.generated.h"

UCLASS()
class TANKZ_API ACannon : public AActor {
  GENERATED_BODY()

public:
  ACannon();

  void Fire();
  void FireBrust();
  bool IsReadyToFire();
  void Reload();

  void FireSpecial();
  bool IsReadyToFireSpecial();
  void ReloadSpecial();
  
  void ViewAmmo();
  void EmptyAmmo();

protected:
  virtual void BeginPlay() override;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
  class UStaticMeshComponent* CannonMesh;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
  class UArrowComponent* ProjectileSpawnPoint;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
  ECannonType CannonType = ECannonType::FireProjectile;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
  float FireRate =  1.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
  float FireRange = 1000.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
  float Damage = 1.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
  uint8 Ammo = 30;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
  uint8 BurstShooting = 5;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
  float BrustFireRate = 0.25f;

  UPROPERTY()
  uint8 NumberBurst = 0;

  bool bReadyToFire = true;

  FTimerHandle ReloadTimer;
  FTimerHandle BrustTimer;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire special params")
  ECannonType CannonTypeSpecial = ECannonType::FireSpecial;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire special params")
  float FireRateSpecial = 4.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire special params")
  float FireRangeSpecial = 2000.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire special params")
  float DamageSpecial = 10.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
  uint8 AmmoSpecial = 5;

  bool bReadyToFireSpecial = true;

  FTimerHandle ReloadTimerSpecial;

};