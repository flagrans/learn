// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStructs.generated.h"

UENUM(BlueprintType)
enum class ECannonType : uint8 
{ 
	FireTrace = 0 UMETA(DisplayName = "Use Trace"),
	FireProjectile = 1 UMETA(DisplayName = "Use Projectile"), 
	FireSpecial = 2 UMETA(DisplayName = "Use Fire Special")
};

UCLASS()
class TANKZ_API UGameStructs : public UObject
{
	GENERATED_BODY()
	
};
