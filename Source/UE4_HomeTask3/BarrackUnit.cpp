// Fill out your copyright notice in the Description page of Project Settings.

#include "BarrackUnit.h"
#include <ConstructorHelpers.h>


// Sets default values
ABarrackUnit::ABarrackUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	MoveDirection = FVector(-20.0f, 0.0f, 0.0f);
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("BarrackUnit");
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshForUnit(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (MeshForUnit.Object) {
		MeshComponent->SetStaticMesh(MeshForUnit.Object);
	}
	RootComponent = Cast<USceneComponent>(MeshComponent);
	
}

// Called when the game starts or when spawned
void ABarrackUnit::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentPosition = GetActorLocation();
}

// Called every frame
void ABarrackUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//SetActorLocation(GetActorLocation() + MoveDirection);
}

// Called to bind functionality to input
void ABarrackUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

