// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"


ABasePlayer::ABasePlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	SceletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SceletalMesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	RootComponent = SceletalMesh;
	SpringArm->SetupAttachment(SceletalMesh);
	Camera->SetupAttachment(SpringArm);

	MovementForce = 10000;
	JumpImpulse = 1000;
	jumping = false;
}

void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (jumping)
		Jump();
}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &ABasePlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABasePlayer::MoveRight);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ABasePlayer::CheckJumping);
	InputComponent->BindAction("Jump", IE_Released, this, &ABasePlayer::CheckJumping);
}

void ABasePlayer::MoveForward(float value)
{
	FVector ForceToAdd{ FVector(1,0,0) * value * MovementForce };
	SceletalMesh->AddForce(ForceToAdd);
}

void ABasePlayer::MoveRight(float value)
{
	FVector ForceToAdd{ FVector(0,1,0) * value * MovementForce };
	SceletalMesh->AddForce(ForceToAdd);
}

void ABasePlayer::CheckJumping()
{
	if (jumping)
		jumping = false;
	else
		jumping = true;
}
