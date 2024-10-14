// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//#include "Camera/CameraComponent.h"
#include "InputAction.h"
#include <EnhancedInputSubsystems.h>
#include "WorldManagerSubsystem.h"

#include "BasePlayerPawn.generated.h"


class UCameraComponent;

UCLASS()
class CITYBUILDER_API ABasePlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* OurCamera;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//INPUT
	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> NavigationInputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* HorizontalNavigationAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* VerticalNavigationAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ZoomNavigationAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SwitchModeAction;

private:
	UPROPERTY(EditAnywhere)
	float CameraZoom = 250.0f;
	UPROPERTY(EditAnywhere)
	float CameraMaxZoom = 1500.0f;
	UPROPERTY(EditAnywhere)
	float CameraMinZoom = 50.0f;
	UPROPERTY(EditAnywhere)
	float CameraTilt = 45.0f;

	float CameraZoomAcceleration;

	// Camera speed 
	/** value used by the controller to set current accel based on input */
	UPROPERTY(EditAnywhere)
	float CameraDefaultAcceleration;
	UPROPERTY(EditAnywhere)
	float CameraDefaultZoom;

	FVector CameraAcceleration; //current accel
	FVector CameraSpeed; //current speed
	UPROPERTY(EditAnywhere)
	float CameraMaxSpeed = 100.0f;

	void Move_XAxis(const FInputActionInstance& Instance);
	void Move_YAxis(const FInputActionInstance& Instance);
	void Zoom_Camera(const FInputActionInstance& Instance);
	void SwitchMode(const FInputActionInstance& Instance);

	void Click(const FInputActionInstance& Instance);


};
