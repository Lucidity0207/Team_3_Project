// Fill out your copyright notice in the Description page of Project Settings.


#include "CatActivatorParent.h"
#include "Team_3_ProjectCharacter.h"
#include "Components/BoxComponent.h"

// Sets default values
ACatActivatorParent::ACatActivatorParent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionVolume"));
}

// Called when the game starts or when spawned
void ACatActivatorParent::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &ACatActivatorParent::OnOverlapBegin);
}

// Called every frame
void ACatActivatorParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACatActivatorParent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		ATeam_3_ProjectCharacter* Char = Cast<ATeam_3_ProjectCharacter>(OtherActor);
		if (Char)
		{
			UE_LOG(LogTemp, Warning, TEXT("Spawn cat"));
		}
	}
}