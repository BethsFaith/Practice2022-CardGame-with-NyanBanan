// Fill out your copyright notice in the Description page of Project Settings.

#include "Deck.h"


ADeck::ADeck()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADeck::BeginPlay()
{
	srand(time(0));
	rand();
	MyGameMode = (ACardGameMode*)UGameplayStatics::GetGameMode(this);
	Super::BeginPlay();

}

void ADeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ACard* ADeck::GiveACard(int index) {
	if (Deck[index] == nullptr || index<0 || index>Deck.Num() - 1)
		return nullptr;
	ACard* temp = Deck[index];
	Deck[index] = nullptr;
	return temp;
}

void ADeck::DrawACardAtEnd()
{
	if (this->IsEmpty()) return;
	for (int k = 0; k < 4; ++k) {
		if (MyHand[k]->GetCard() == nullptr) {
			int place = rand() % this->Deck.Num();
			ACard* drawedCard = this->GiveACard(place);
			if (drawedCard == nullptr) {
				int i = place;
				int j = place;
				while (this->Deck[i] == nullptr && this->Deck[j] == nullptr) {
					if (i < this->Deck.Num() - 1) ++i;
					if (j > 0) --j;
				}
				if (this->Deck[i] != nullptr)
					drawedCard = this->GiveACard(i);
				else if (this->Deck[j] != nullptr)
					drawedCard = this->GiveACard(j);
			}
			(MyHand[k]->SetAndMoveCardInHand(drawedCard));
			return;
		}
	}	
}

bool ADeck::IsEmpty()
{
	for (auto& x : Deck) {
		if (x != nullptr)
			return false;
	}
	return true;
}

void ADeck::PickAHand(bool IsEnemys)
{
	if (IsEnemys) {
		MyHand = MyGameMode->GetEnemyHandCards();
		MyTable = MyGameMode->GetEnemyPlaces();
	}
	else {
		MyHand = MyGameMode->GetPlayerHandCards();
		MyTable = MyGameMode->GetPlayerPlaces();		
	}
}

void ADeck::TakeACard(ACard* iCard)
{
	int i = 0;
	while (this->Deck[i] != nullptr)
		++i;
	this->Deck[i] = iCard;
	iCard->MoveAndRotate(0, 0, -300, 0, 0, 0);
}



