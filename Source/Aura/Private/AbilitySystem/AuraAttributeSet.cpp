// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAttributeSet.h"

#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);

	InitMana(25.f);
	InitMaxMana(50.f);
}

void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//注册要执行网络同步复制的参数(COND: 客户端筛选条件,None为在所有客户端复制.  REPNOTIFY为触发OnRep_Health时机, Always意思是不管Health值是否改变，只要同步Set了就触发)
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UAuraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	//用服务器验证完的Health去覆盖本地的Health(FProperty)，再去通知所有GE
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, OldHealth);
}

void UAuraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, OldMaxHealth);
}

void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, OldMana);
}

void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, OldMaxMana);
}

void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxHealth());
	}

	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxMana());
	}
	
}


void UAuraAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties EffectProperties;
	SetEffectProperties(Data, EffectProperties);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0, GetMaxMana()));
	}
}

void UAuraAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& InEffectProperties)
{
	//Source Properties
	FGameplayEffectContextHandle EffectContextHandle = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* SourceASC = EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	InEffectProperties.EffectContextHandle = EffectContextHandle;
	InEffectProperties.SourceASC = SourceASC;
	
	if (IsValid(SourceASC) && SourceASC->AbilityActorInfo.IsValid() && SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		AActor* SourceAvatarActor = SourceASC->GetAvatarActor();
		AController* SourceController = SourceASC->AbilityActorInfo->PlayerController.Get();

		//当ASC在PlayerState上时，PlayerState没有Controller引用，此时需要去AvatarActor里获取
		if (SourceAvatarActor && !SourceController)
		{
			if (const APawn* SourcePawn = Cast<APawn>(SourceAvatarActor))
			{
				SourceController = SourcePawn->GetController();
			}
		}

		InEffectProperties.SourceAvatarActor = SourceAvatarActor;
		InEffectProperties.SourceController = SourceController;
		
		if (SourceController)
		{
			InEffectProperties.SourceCharacter = Cast<ACharacter>(SourceController->GetPawn());
		}
	}

	//TargetProperties
	UAbilitySystemComponent& TargetASCRef = Data.Target;
	
	if (TargetASCRef.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		AActor* TargetAvatarActor = TargetASCRef.GetAvatarActor();
		AController* TargetController = TargetASCRef.AbilityActorInfo->PlayerController.Get();

		if (TargetAvatarActor && !TargetController)
		{
			if (const APawn* TargetPawn = Cast<APawn>(TargetAvatarActor))
			{
				TargetController = TargetPawn->GetController();
			}
		}

		InEffectProperties.TargetASC = TargetASCRef.AbilityActorInfo->AbilitySystemComponent.Get();
		InEffectProperties.TargetAvatarActor = TargetAvatarActor;
		InEffectProperties.TargetController = TargetController;

		if (TargetController)
		{
			InEffectProperties.TargetCharacter = Cast<ACharacter>(TargetController->GetPawn());
		}
	}
}
