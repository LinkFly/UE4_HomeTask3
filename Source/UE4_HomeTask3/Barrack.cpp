// Fill out your copyright notice in the Description page of Project Settings.

#include "Barrack.h"
#include <Engine.h>
#include <UObjectBaseUtility.h>


// Sets default values
ABarrack::ABarrack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Barrack");
	Mesh->SetRelativeLocation(FVector(250, 0, -70));
	//Mesh->SetRelativeRotation(FQuat(0, 0, 180, 1));
	//ConstructorHelpers::FObjectFinder<UStaticMesh> LoadedMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> LoadedMesh(TEXT("StaticMesh'/Game/Developers/michalorzelek/Barracs/SM_Barracks_S2.SM_Barracks_S2'"));

	
	if (LoadedMesh.Object) {
		Mesh->SetStaticMesh(LoadedMesh.Object);
	}
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("BarrackScene");
	Mesh->SetupAttachment(Root);
	RootComponent = Root;
}

// Called when the game starts or when spawned
void ABarrack::BeginPlay()
{
	Super::BeginPlay();
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	SetActorLocation(Player->GetActorLocation());
	GetWorldTimerManager().SetTimer(Timer, this, &ABarrack::CreateUnit, 2, true);
	
}

void ABarrack::CreateUnit()
{
	//GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, TEXT("This is CreateUnit"));
	//ABarrackUnit* BarrackUnit = NewObject<ABarrackUnit>(this, ABarrackUnit::StaticClass());
	//BarrackUnit->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
	//BarrackUnit->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
	FTransform TestPoint;
	AActor* Actor = GetWorld()->SpawnActor(ABarrackUnit::StaticClass(), &TestPoint);
	ABarrackUnit* BarrackUnit = Cast<ABarrackUnit>(Actor);
	BarrackUnit->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));

	UMoveComponent* MyMove = NewObject<UMoveComponent>(BarrackUnit, UMoveComponent::StaticClass());
	MyMove->RegisterComponent();
	BarrackUnit->AddInstanceComponent(MyMove);
}

// Called every frame
void ABarrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

