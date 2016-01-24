// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class FLYFLYFLYER_API AProjectile : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	//AProjectile();
	AProjectile(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComp;

	///** Projectile movement component */
	//UPROPERTY(VisibleAnywhere, /*BlueprintReadOnly,*/ Category = Movement)
	//	UProjectileMovementComponent* ProjectileMovement;

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** inits velocity of the projectile in the shoot direction */
	void InitVelocity(const FVector& ShootDirection);
};
