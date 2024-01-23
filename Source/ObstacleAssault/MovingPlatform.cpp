// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// 액터 포지션 받아오기
	FVector CurrentLocation = GetActorLocation();

	// 현재위치 갱신 
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	
	// 해당 위치로 이동 
	SetActorLocation(CurrentLocation);

	// 시작위치에서 얼마나 멀어졌는지를 계산 
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	// 지정해둔 값보다 더 멀어졌다면 true
	bool Result = DistanceMoved > MoveDistance;
	if (true == Result)
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

