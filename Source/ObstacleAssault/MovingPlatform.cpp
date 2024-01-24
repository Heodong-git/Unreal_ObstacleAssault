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

	UE_LOG(LogTemp, Display, TEXT("Your meassage"));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	if (true == Rotation)
	{
		RotatePlatform(DeltaTime);
	}
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// ���� ������ �޾ƿ���
	FVector CurrentLocation = GetActorLocation();

	// ������ġ ���� 
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

	// �ش� ��ġ�� �̵� 
	SetActorLocation(CurrentLocation);
	// �����ص� ������ �� �־����ٸ� true
	
	if (true == ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	bool Result = GetDistanceMoved() > MoveDistance;
	return Result;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

