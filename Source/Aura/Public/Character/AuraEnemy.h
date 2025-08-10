// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"

#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CharacterClassDefault")
	int32 ActorLevel = 1;
	
public:
	AAuraEnemy();

	/** Enemy Interface */
	virtual void HighLightActor() override;
	virtual void UnHighlightActor() override;
	/** End Enemy Interface */

	/** Combat Interface */
	virtual int32 GetActorLevel() const override;
	/** End Combat Interface*/

protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
};
