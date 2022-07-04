// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCRPlayer.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ABaseCRPlayer::ABaseCRPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	Speed = 500;
	GetCharacterMovement()->MaxWalkSpeed = Speed;
	jumping = false;
	running = false;
}

void ABaseCRPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCRPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCRPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCRPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCRPlayer::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &ABaseCRPlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ABaseCRPlayer::AddControllerPitchInput);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCRPlayer::CheckJumping);
	InputComponent->BindAction("Jump", IE_Released, this, &ABaseCRPlayer::CheckJumping);

	InputComponent->BindAction("ToggleRun", IE_Pressed, this, &ABaseCRPlayer::CheckRunning);

	InputComponent->BindAction("Sprint", IE_Pressed, this, &ABaseCRPlayer::CheckRunning);
	InputComponent->BindAction("Sprint", IE_Released, this, &ABaseCRPlayer::CheckRunning);
}

void ABaseCRPlayer::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void ABaseCRPlayer::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ABaseCRPlayer::CheckJumping()
{
	if (jumping)
		jumping = false;
	else
	{
		jumping = true;
		Jump();
	}
}

void ABaseCRPlayer::CheckRunning()
{
	if (running)
	{
		running = false;
		GetCharacterMovement()->MaxWalkSpeed = 1 * Speed;
	}
	else
	{
		running = true;
		GetCharacterMovement()->MaxWalkSpeed = 2 * Speed;
	}
}

