// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGameCamera.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

ACardGameCamera::ACardGameCamera()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACardGameCamera::BeginPlay()
{
	Super::BeginPlay();
	CameraOne = (AActor*)GetWorld()->SpawnActor<ACameraActor>(FVector(-3040, 2360, 2160), FRotator(-30, 0, 0));
	CameraTwo = (AActor*)GetWorld()->SpawnActor<ACameraActor>(FVector(870, 1710, 3880), FRotator(-70, 0, 0));
	CameraThree = (AActor*)GetWorld()->SpawnActor<ACameraActor>(FVector(3730, 1650, 3040), FRotator(-90, 0, 0));
	UGameplayStatics::GetPlayerController(this, 0)->SetViewTarget(Cast<AActor>(CameraOne));
}

void ACardGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACardGameCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("NextCamera", IE_Pressed, this, &ACardGameCamera::NextCamera);
	InputComponent->BindAction("PrevCamera", IE_Pressed, this, &ACardGameCamera::PrevCamera);

}

void ACardGameCamera::NextCamera()
{
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (OurPlayerController) {
		switch (this->CameraNumber)
		{
		case 0:
			OurPlayerController->SetViewTarget(CameraTwo);
			++(this->CameraNumber);
			break;
		case 1:
			OurPlayerController->SetViewTarget(CameraThree);
			++(this->CameraNumber);
			break;
		default:
			break;
		}
	}
}

void ACardGameCamera::PrevCamera()
{
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (OurPlayerController) {
		switch (this->CameraNumber)
		{
		case 1:
			OurPlayerController->SetViewTarget(CameraOne);
			--(this->CameraNumber);
			// если в руке есть карта, положить ее на место
			if (SelectedCard != nullptr)
			{
				FVector loc = SelectedCard->GetLastLocation();
				FRotator rot = SelectedCard->GetLastRotation();
				SelectedCard->MoveAndRotate(loc.X, loc.Y, loc.Z, rot.Pitch, rot.Yaw, rot.Roll);
				SelectedCard = nullptr;
			}
			break;
		case 2:
			OurPlayerController->SetViewTarget(CameraTwo);
			--(this->CameraNumber);
			break;
		default:
			break;
		}
	}
}

const int& ACardGameCamera::GetCameraNumber()
{
	return CameraNumber;
}

ACard* ACardGameCamera::GetSelectedCard()
{
	return SelectedCard;
}

void ACardGameCamera::SetSelectedCard(ACard* InputCard)
{
	SelectedCard = InputCard;
}

ACard* ACardGameCamera::GetZoomedCard()
{
	return ZoomedCard;
}


void ACardGameCamera::SetZoomedCard(ACard* InputCard)
{
	ZoomedCard = InputCard;
}
