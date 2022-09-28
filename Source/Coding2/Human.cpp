// Fill out your copyright notice in the Description page of Project Settings.


#include "Human.h"

// Sets default values
AHuman::AHuman()	// the constructor for the class
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHuman::BeginPlay()
{
	Super::BeginPlay();

	// setup elements
	// Elements[0] = "Fire";
	// Elements[1] = "Ice";
	// Elements[2] = "Candy";
	// Elements[3] = "Fire";

	// PlayerName = "Bob";

	RandomizeHuman();		// calling the randomize human function
	
}

// Called every frame
void AHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// return type is void

/*

*/
void AHuman::RandomizeHuman() {
	UE_LOG(LogTemp, Display, TEXT("Randomizing Human!"));

	float RandomNumber = FMath::RandRange(0, 10);
	UE_LOG(LogTemp, Display, TEXT("Random: %f"), RandomNumber);

	int RandElement = FMath::RandRange(0,3);
	
	// UE_LOG(LogTemp, Display, TEXT("Player is a(n) %s elemental."), Elements[RandElement]);
	UE_LOG(LogTemp, Display, TEXT("Player is a(n) %s elemental."), *Elements[RandElement]);

	Speed = FMath::RandRange(5.0, 25.0);

	ElementalType = RandElement;

}


void AHuman::TakeDamage(AHuman* attacker) {
	// if attacker is equal to null, don't do anything else.
	if (!attacker) return;

	UE_LOG(LogTemp, Display, TEXT("At the top of TakeDamage()"));

	


	UE_LOG(LogTemp, Display, TEXT("My attacker's name is %s"), *attacker->PlayerName);

	float DmgMuliplier = DamageMultiplier(attacker->ElementalType);

	// // longer way to do it
	// health = health - damange * multiplier;  // this is a lot to type

	// health - damage;		// this does nothing

	Health -= attacker->Damage * DmgMuliplier;  // this is da best

	UE_LOG(LogTemp, Display, TEXT("I now have %f health."), Health);
}

float AHuman::DamageMultiplier(int32 GivenElemType) {
	UE_LOG(LogTemp, Display, TEXT("At the top of DamageMultiplier()"));


	float Multiplier = 1;		//default value is no change.

	Multiplier = FMath::RandRange(.5, 2.0);

	// if(GivenElemType == ElementalType) {
	// 	Multiplier = 0.5;
	// }
	// // if attacker is fire and i am ice
	// else if(GivenElemType == 0 && ElementalType == 1) {
	// 	Multiplier = 2.0;		// is this a float or a double?
	// }
	// // if attacker is ict and i am fire
	// else if(GivenElemType == 1 && ElementalType == 0) {
	// 	Multiplier = 2.0;		// is this a float or a double?
	// }
	// else {
	// 	Multiplier = 1;
	// }
	


	return Multiplier;
}

float AHuman::GetHealth() const {
	return Health;
}

void AHuman::SetHealth(const float By) {
	Health += By;
}