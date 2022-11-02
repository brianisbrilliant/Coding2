// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class CODING2_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// My changes start at the finish
	UPROPERTY(EditAnywhere)
	bool Respawn = true;

	UPROPERTY(EditAnywhere)
	bool Collected = false;

	UPROPERTY(EditAnywhere)
	float RespawnInterval = 4.0;

	UPROPERTY(EditAnywhere)
	float RespawnTimeRemaining = 0;

	UPROPERTY(EditAnywhere)
	AActor* ObjectToSpawn;			// I can't figure out how to get this to be an actor from /Content/

	//UPROPERTY(EditAnywhere)
	//box collision that tells us when the obj has been collected.

	UFUNCTION(BlueprintCallable)
	void Collect();

	UFUNCTION(BlueprintCallable)
	void Spawn();


};
