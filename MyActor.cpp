#include "MyActor.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// Bind the collision event function to the OnComponentHit event
	UPrimitiveComponent* PrimitiveComponent = FindComponentByClass<UPrimitiveComponent>();
	if (PrimitiveComponent)
	{
		PrimitiveComponent->OnComponentHit.AddDynamic(this, &AMyActor::OnCollision);
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Collision event handler
void AMyActor::OnCollision(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherComp && OtherActor->GetFName() == FName("ObjectName"))
	{
		OtherActor->SetActorLocation(TeleportLocation);
	}
}
}
