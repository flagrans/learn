// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStruct.generated.h"

UENUM(BluePrintType)
enum class ECannonType : uint8
{
	FireTrace = 0 UMETA(DisplayName = "Use Trace"),
	FireProjectile = 1 UMETA(DisplayName = "Use projectile"),
	
	FireSpecial = 2 UMETA(DisplayName = "Special Fire")
};

USTRUCT()
struct FDamageData
{
	GENERATED_BODY()

	float DamageValue;

	AActor* Instigator;

	AActor* DamageMaker;

};

UCLASS()
class TANKOGEDDON_API UGameStruct : public UObject
{
	GENERATED_BODY()
	
};
