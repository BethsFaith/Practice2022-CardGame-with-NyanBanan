// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.h"
#include "CardGameMode.h"
#include <Kismet/GameplayStatics.h>
#include "Deck.generated.h"

UCLASS()
class PRACTICE2022_API ADeck : public AActor
{
	GENERATED_BODY()
	
public:	
	ADeck();

protected:
	virtual void BeginPlay() override;
	
public:	
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ACard*> Deck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ACardGameMode* MyGameMode;
	TArray<ACardPlace*> MyHand;
	TArray<ACardPlace*> MyTable;


	UFUNCTION(BlueprintCallable)
		ACard* GiveACard(int index);
	UFUNCTION(BlueprintCallable)
		void DrawACardAtEnd();
	UFUNCTION(BlueprintCallable)
		bool IsEmpty();
	UFUNCTION(BlueprintCallable)
		void PickAHand(bool IsEnemys);
	UFUNCTION(BlueprintCallable)
		void TakeACard(ACard* iCard);


private:
	

};
