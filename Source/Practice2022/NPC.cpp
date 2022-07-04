// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"
#include "MyHUD.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "BaseCRPlayer.h"


ANPC::ANPC()
{
	PrimaryActorTick.bCanEverTick = true;

	ProxSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Proximity Sphere"));
	ProxSphere->SetupAttachment(RootComponent);
	ProxSphere->SetSphereRadius(400.f);

	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPC::Prox);
	NPCMessage = "Hi";// сообщение по умолчанию, может быть отредактировано
	MessageTime = 5.f;
	MessageColor = FColor::White;
}


void ANPC::BeginPlay()
{
	Super::BeginPlay();
}

void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANPC::Prox_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent*
	OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult&
	SweepResult)
{
	// если актор, с которым произошло пересечение, это не игрок, вернуться из функции
	if (Cast<ABaseCRPlayer>(OtherActor) == nullptr)
		return;

	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	if (PController)
	{
		AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());
		if (hud != nullptr)
			hud->addMessage(FMessage(Face, Name + FString(": ") + NPCMessage, MessageTime, MessageColor));
	}
}
