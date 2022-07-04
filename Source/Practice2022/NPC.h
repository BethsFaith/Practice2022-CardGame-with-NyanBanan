// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "NPC.generated.h"

UCLASS()
class PRACTICE2022_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	ANPC();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
	USphereComponent* ProxSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	FString NPCMessage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	float MessageTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	FColor MessageColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCName)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	UTexture2D* Face;

	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
	void Prox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
