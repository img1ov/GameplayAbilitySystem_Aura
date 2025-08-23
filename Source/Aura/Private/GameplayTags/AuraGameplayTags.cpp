// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayTags/AuraGameplayTags.h"

/** Primary Attribute Tags */

UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Primary_Strength,"Attributes.Primary.Strength", "Increases physical damage.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Primary_Intelligence,"Attributes.Primary.Intelligence", "Increases magical damage.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Primary_Resilience,"Attributes.Primary.Resilience", "Increases Armor and Armor Penetration.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Primary_Vigor,"Attributes.Primary.Vigor", "Increases Health.")


/** Secondary Attribute Tags */

UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_Armor,"Attributes.Secondary.Armor", "Reduces damage taken, improves Block Chance.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_ArmorPenetration,"Attributes.Secondary.ArmorPenetration", "Ignored Percentage of enemy Armor, increases Critical Hit Chance.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_BlockChance,"Attributes.Secondary.BlockChance", "Chance to cut incoming damage in half.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_CriticalChance,"Attributes.Secondary.CriticalChance", "Chance to double damage plus critical hit bonus.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_CriticalHitDamage,"Attributes.Secondary.CriticalHitDamage", "Bonus damage added when a critical hit is scored.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_CriticalHitResistance,"Attributes.Secondary.CriticalHitResistance", "Reduces Critical Hit Chance of attacking enemies.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_HealthRegeneration,"Attributes.Secondary.HealthRegeneration", "Amount of health regeneration every 1 second.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_ManaRegeneration,"Attributes.Secondary.ManaRegeneration", "Amount of mana regeneration every 1 second.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_MaxHealth,"Attributes.Secondary.MaxHealth", "Maximum amount of Health obtainable.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_MaxMana,"Attributes.Secondary.MaxMana", "Maximum amount of Mana obtainable.")


/** Input Tags */

UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_LMB, "InputTag.LMB", "InputTag for left mouse button.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_RMB, "InputTag.RMB", "InputTag for rgiht mouse button.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_1, "InputTag.1", "InputTag for 1 key.")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_2, "InputTag.2", "InputTag for 2 key")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_3, "InputTag.3", "InputTag for 3 key")
UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_4, "InputTag.4", "InputTag for 4 key")