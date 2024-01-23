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
	
	// ���� ������ �޾ƿ���
	FVector CurrentLocation = GetActorLocation();

	// ������ġ ���� 
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	
	// �ش� ��ġ�� �̵� 
	SetActorLocation(CurrentLocation);

	// ������ġ���� �󸶳� �־��������� ��� 
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	// �����ص� ������ �� �־����ٸ� true
	bool Result = DistanceMoved > MoveDistance;
	if (true == Result)
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

