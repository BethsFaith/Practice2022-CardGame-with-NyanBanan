// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "BasePlayer.generated.h"

UCLASS()
class PRACTICE2022_API ABasePlayer : public APawn
{
	GENERATED_BODY()

public:
	ABasePlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* SceletalMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpImpulse;

	UPROPERTY()
	bool jumping;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void CheckJumping();

	UFUNCTION(BlueprintImplementableEvent)
	void Jump();
};
