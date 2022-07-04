// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "BaseCRPlayer.generated.h"

UCLASS()
class PRACTICE2022_API ABaseCRPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCRPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float Value);
	UFUNCTION()
	void MoveRight(float Value);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool jumping;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool running;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	void CheckJumping();
	void CheckRunning();
};