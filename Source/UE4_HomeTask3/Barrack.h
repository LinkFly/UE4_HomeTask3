// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Core/Public/Math/Quat.h"
#include "BarrackUnit.h"
#include "MoveComponent.h"
#include "Barrack.generated.h"

UCLASS()
class UE4_HOMETASK3_API ABarrack : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY()
		UStaticMeshComponent* Mesh;

	UPROPERTY()
		FTimerHandle Timer;
public:	
	// Sets default values for this actor's properties
	ABarrack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void CreateUnit();

	UStaticMesh* MeshUnits;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
};
