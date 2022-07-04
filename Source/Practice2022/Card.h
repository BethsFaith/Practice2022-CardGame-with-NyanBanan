// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <Runtime/Engine/Classes/Components/TextRenderComponent.h>
#include "Card.generated.h"


UCLASS()
class PRACTICE2022_API ACard : public AActor
{
	GENERATED_BODY()

public:
	ACard();
protected:
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Card_Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Picture_Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTextRenderComponent* Text_HP;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) 
	UTextRenderComponent* Text_Damage;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTextRenderComponent* Text_Name;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTextRenderComponent* Text_Effect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HP = 99;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Damage = 99;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name = FText::FromString("TEST");
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Effect = FText::FromString("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsZoomed = false;

	UFUNCTION(BlueprintCallable)
	void VisualStats();

	UFUNCTION(BlueprintCallable)
	void SetLastLocation(FVector loc);

	UFUNCTION(BlueprintCallable)
	FVector GetLastLocation();
	FRotator GetLastRotation();

	UFUNCTION(BlueprintImplementableEvent)
	void BattleCry();

	void MoveAndRotate(float x, float y, float z, double pitch, double yaw, double roll);
	UFUNCTION(BlueprintCallable)
	bool isDead();
	UFUNCTION(BlueprintCallable)
	void Attack(ACard* DamageRecipient);
	void SetProperties(int HP_, int Damage_, FText Name_, FText Effect_);

	friend void AttackEachOther(ACard* Card1, ACard* Card2);
private:
	FVector MyLastLocation;
	FRotator MyLastRotation;
};

