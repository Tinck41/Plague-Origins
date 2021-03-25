#pragma once
#include "stdafx.h"
#include "GlobalFactory.h"

GlobalFactory::GlobalFactory()
{
	texture1.loadFromFile("./Assets/AnimationSep2/heroAnim/heroAnimAttack_tex.png");
	texture2.loadFromFile("./Assets/AnimationSep2/heroAnim/heroAnimRun_tex.png");
	texture3.loadFromFile("./Assets/Animation/enemyAnim/enemyAnim_tex.png");
	//this->zf = fact.get();
	
	//this->zf->addDragonBonesData(fact.getDragonBonesData("heroAnimAttack"), "heroAnimAttack");
	//this->zf->loadDragonBonesData("./Assets/AnimationSep2/heroAnim/heroAnimAttack_ske.json");
	//this->zf->loadTextureAtlasData("./Assets/AnimationSep2/heroAnim/heroAnimAttack_tex.json", &texture1);
	//this->zf->loadDragonBonesData("./Assets/AnimationSep2/heroAnim/heroAnimRun_ske.json");
	//this->zf->loadTextureAtlasData("./Assets/AnimationSep2/heroAnim/heroAnimRun_tex.json", &texture2);
	//this->zf->loadDragonBonesData("./Assets/Animation/enemyAnim/enemyAnim_ske.json");
	//this->zf->loadTextureAtlasData("./Assets/Animation/enemyAnim/enemyAnim_tex.json", &texture3);
}

dragonBones::SFMLFactory& GlobalFactory::factorySet()
{
	dragonBones::SFMLFactory fact;
	
	fact.loadDragonBonesData("./Assets/AnimationSep2/heroAnim/heroAnimAttack_ske.json");
	fact.loadTextureAtlasData("./Assets/AnimationSep2/heroAnim/heroAnimAttack_tex.json", &texture1);

	fact.loadDragonBonesData("./Assets/AnimationSep2/heroAnim/heroAnimRun_ske.json");
	fact.loadTextureAtlasData("./Assets/AnimationSep2/heroAnim/heroAnimRun_tex.json", &texture2);

	fact.loadDragonBonesData("./Assets/Animation/enemyAnim/enemyAnim_ske.json");
	fact.loadTextureAtlasData("./Assets/Animation/enemyAnim/enemyAnim_tex.json", &texture3);

	return fact;
}