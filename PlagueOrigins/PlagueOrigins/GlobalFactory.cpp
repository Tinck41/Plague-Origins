#pragma once
#include "stdafx.h"
#include "GlobalFactory.h"

GlobalFactory::GlobalFactory()
{
	heroAttackU.loadFromFile("./Assets/AnimationSep/heroAnim/heroAttackU_tex.png");
	heroAttackR.loadFromFile("./Assets/AnimationSep/heroAnim/heroAttackR_tex.png");
	heroAttackD.loadFromFile("./Assets/AnimationSep/heroAnim/heroAttackD_tex.png");
	heroMoveU.loadFromFile("./Assets/AnimationSep/heroAnim/heroMoveU_tex.png");
	heroMoveR.loadFromFile("./Assets/AnimationSep/heroAnim/heroMoveR_tex.png");
	heroMoveD.loadFromFile("./Assets/AnimationSep/heroAnim/heroMoveD_tex.png");
	dogAnim.loadFromFile("./Assets/Animation/dogAnim/dogAnim_tex.png");

	//HERO
	factory.loadDragonBonesData("./Assets/AnimationSep/heroAnim/heroAttackU_ske.json");
	factory.loadTextureAtlasData("./Assets/AnimationSep/heroAnim/heroAttackU_tex.json", &heroAttackU);
	factory.loadDragonBonesData("./Assets/AnimationSep/heroAnim/heroAttackR_ske.json");
	factory.loadTextureAtlasData("./Assets/AnimationSep/heroAnim/heroAttackR_tex.json", &heroAttackR);
	factory.loadDragonBonesData("./Assets/AnimationSep/heroAnim/heroAttackD_ske.json");
	factory.loadTextureAtlasData("./Assets/AnimationSep/heroAnim/heroAttackD_tex.json", &heroAttackD);
	
	factory.loadDragonBonesData("./Assets/AnimationSep/heroAnim/heroMoveU_ske.json");
	factory.loadTextureAtlasData("./Assets/AnimationSep/heroAnim/heroMoveU_tex.json", &heroMoveU);
	factory.loadDragonBonesData("./Assets/AnimationSep/heroAnim/heroMoveR_ske.json");
	factory.loadTextureAtlasData("./Assets/AnimationSep/heroAnim/heroMoveR_tex.json", &heroMoveR);
	factory.loadDragonBonesData("./Assets/AnimationSep/heroAnim/heroMoveD_ske.json");
	factory.loadTextureAtlasData("./Assets/AnimationSep/heroAnim/heroMoveD_tex.json", &heroMoveD);
	
	//DOG
	factory.loadDragonBonesData("./Assets/Animation/dogAnim/dogAnim_ske.json");
	factory.loadTextureAtlasData("./Assets/Animation/dogAnim/dogAnim_tex.json", &dogAnim);
}

GlobalFactory& GlobalFactory::Instance()
{
	static GlobalFactory gFactory;
	return gFactory;
}
