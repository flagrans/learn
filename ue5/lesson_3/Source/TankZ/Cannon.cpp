

#include "Cannon.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"

ACannon::ACannon()
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent *SceneComp =
            CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent = SceneComp;

	CannonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CanonMesh"));
    CannonMesh->SetupAttachment(SceneComp);

	ProjectileSpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
    ProjectileSpawnPoint->SetupAttachment(CannonMesh);
}


//void ACannon::Fire() {
//    if (!IsReadyToFire())
//    {
//      return;
//    }
//    if (CannonType == ECannonType::FireProjectile) {
//      GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, "Fire Projectile");
//      //GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, FString::Printf(TEXT("Ammo: %d", 5)));
//    } else {
//      GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Fire Trace");
//    }
//    bReadyToFire = false;
//    Ammo--;
//    ViewAmmo();
//
//    GetWorld()->GetTimerManager().SetTimer(ReloadTimer, this, &ACannon::Reload, FireRate, false);
//}


// ¬ задании не сказано что не может производитс€ одновременно стрельба из 2-х орудий, 
// поэтому допускаетс€ что во врем€ серии стрельбы, можно пальнуть из FireSpecial

void ACannon::Fire() {
    if (!IsReadyToFire()) {
      return;
    }
    if (CannonType == ECannonType::FireProjectile) {
      GetWorld()->GetTimerManager().SetTimer(BrustTimer, this, &ACannon::FireBrust, BrustFireRate, true, 0.1f);
    } else {
      GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Fire Trace");
    }
    bReadyToFire = false;
    Ammo--;
}

void ACannon::FireBrust() {
    NumberBurst++;
    if (NumberBurst > 5) {
      NumberBurst = 0;
      GetWorld()->GetTimerManager().ClearTimer(BrustTimer);
      ViewAmmo();
      GetWorld()->GetTimerManager().SetTimer(ReloadTimer, this,
                                             &ACannon::Reload, FireRate, false);
      return;
    }
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("FireBrust #: %d"), NumberBurst));
}

bool ACannon::IsReadyToFire() { 
    if (!Ammo) {
      EmptyAmmo();
      return false;
    }
    if (!bReadyToFire)
    {
      GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Fire Trace on reload");
    }
    return bReadyToFire; }

void ACannon::Reload() { bReadyToFire = true; }


void ACannon::FireSpecial() {
    if (!IsReadyToFireSpecial()) {
      return;
    }
    if (CannonTypeSpecial == ECannonType::FireSpecial) {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Orange, "Fire Special");
    } 
    bReadyToFireSpecial = false;
    AmmoSpecial--;
    ViewAmmo();

    GetWorld()->GetTimerManager().SetTimer(ReloadTimerSpecial, this, &ACannon::ReloadSpecial, FireRateSpecial, false);
}

bool ACannon::IsReadyToFireSpecial() { 
    if (!AmmoSpecial)
    {
        EmptyAmmo();
        return false;
    }
    if (!bReadyToFireSpecial) {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red,
                                         "FireSpecial on reload");
    }
    return bReadyToFireSpecial; }

void ACannon::ReloadSpecial() { bReadyToFireSpecial = true; }

void ACannon::ViewAmmo() {
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White,
                                     FString::Printf(TEXT("AmmoSpecial: %d"), AmmoSpecial));
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White,
                                     FString::Printf(TEXT("Ammo: %d"), Ammo));
    //ClearOnScreenDebugMessages();
}

void ACannon::EmptyAmmo() {
    if (!AmmoSpecial) {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("AmmoSpecial is null"));
    }
    if (!Ammo) {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Ammo is null"));
    }
}

void ACannon::BeginPlay()
{
  Super::BeginPlay();
  bReadyToFire = true;
  bReadyToFireSpecial = true;
  ViewAmmo();
}