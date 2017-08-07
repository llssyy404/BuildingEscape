// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// Haw far ahead of the player can we reach in cm
	float Reach = 100.f;
	
	class UPhysicsHandleComponent* PhysicsHandle = nullptr;

	class UInputComponent* InputComponent = nullptr;
	
	// Find (assumed) attached physics handle
	void FindPhysicsComponent();

	// Setup (assumed) attached input component
	void SetupInputComponent();

	// Ray-cast and grab what's in reach
	void Grab();

	// Called when grab is released
	void Released();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Returns current start of reach line
	FVector GetReachLineStart();

	// Returns current end of reach line
	FVector GetReachLineEnd();
};
