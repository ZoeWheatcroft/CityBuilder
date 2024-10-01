// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"

// Sets default values
ABasePlayerPawn::ABasePlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// Create a camera and a visible object
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	// Attach our camera and visible object to our root component. Offset and rotate the camera.
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-CameraZoom, 0.0f, CameraZoom));
	OurCamera->SetRelativeRotation(FRotator(-CameraTilt, 0.0f, 0.0f));

}


// Called when the game starts or when spawned
void ABasePlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// update camera speed based on accel
	CameraSpeed += CameraAcceleration;
	CameraSpeed.X = FMath::Clamp(CameraSpeed.X, -CameraMaxSpeed, CameraMaxSpeed);
	CameraSpeed.Y = FMath::Clamp(CameraSpeed.Y, -CameraMaxSpeed, CameraMaxSpeed);
	//TODO: deacceleration

	// update camera position
	FVector CurrentPosition = GetActorLocation();
	FVector NewPosition = CurrentPosition + CameraSpeed * DeltaTime;
	SetActorLocation(NewPosition);

	CameraZoom += CameraZoomAcceleration * DeltaTime;
	CameraZoom = FMath::Clamp(CameraZoom, CameraMinZoom, CameraMaxZoom);
	OurCamera->SetRelativeLocation(FVector(-CameraZoom, 0.0f, CameraZoom));

}

// Called to bind functionality to input
void ABasePlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (Input)
	{
		Input->BindAction(HorizontalNavigationAction, ETriggerEvent::Triggered, this, &ABasePlayerPawn::Move_XAxis);
		Input->BindAction(HorizontalNavigationAction, ETriggerEvent::Completed, this, &ABasePlayerPawn::Move_XAxis);
		Input->BindAction(VerticalNavigationAction, ETriggerEvent::Triggered, this, &ABasePlayerPawn::Move_YAxis);
		Input->BindAction(VerticalNavigationAction, ETriggerEvent::Completed, this, &ABasePlayerPawn::Move_YAxis);
		Input->BindAction(ZoomNavigationAction, ETriggerEvent::Triggered, this, &ABasePlayerPawn::Zoom_Camera);
		Input->BindAction(ZoomNavigationAction, ETriggerEvent::Completed, this, &ABasePlayerPawn::Zoom_Camera);


	}

}


// Update the camera acceleration on X-axis based on A-D input
// This should be triggered also on release
void ABasePlayerPawn::Move_XAxis(const FInputActionInstance& Instance)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("move x axis delegate triggered"));
	if (Instance.GetValue().Get<float>() == 0)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("move x axis delegate COMPLETE"));

	}
	CameraSpeed.X = FMath::Abs(CameraSpeed.X) * Instance.GetValue().Get<float>();
	CameraAcceleration.X = FMath::Abs(CameraDefaultAcceleration) * Instance.GetValue().Get<float>();

}

void ABasePlayerPawn::Move_YAxis(const FInputActionInstance& Instance)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("move y axis delegate triggered"));

	CameraSpeed.Y = FMath::Abs(CameraSpeed.Y) * Instance.GetValue().Get<float>();
	CameraAcceleration.Y = FMath::Abs(CameraDefaultAcceleration) * Instance.GetValue().Get<float>();
}

void ABasePlayerPawn::Zoom_Camera(const FInputActionInstance& Instance)
{
	CameraZoomAcceleration = Instance.GetValue().Get<float>()*CameraDefaultZoom;
}

void ABasePlayerPawn::Click(const FInputActionInstance& Instance)
{
}

