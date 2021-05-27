#pragma once
#include "stdafx.h"
#include "GlobalFactory.h"

GlobalFactory::GlobalFactory()
{
	//LOAD TO FACTORY
	//TEXTURES
	heroAnim.loadFromFile("./Assets/Animation/heroAnim/heroAnim_tex.png");
	dogAnim.loadFromFile("./Assets/Animation/dogAnim/dogAnim_tex.png");
	bishopAnim.loadFromFile("./Assets/Animation/bishopAnim/bishopAnim_tex.png");
	bossAnim.loadFromFile("./Assets/Animation/bossAnim/bossAnim_tex.png");

	//HERO
	factory.loadDragonBonesData("./Assets/Animation/heroAnim/heroAnim_ske.json");
	factory.loadTextureAtlasData("./Assets/Animation/heroAnim/heroAnim_tex.json", &heroAnim);

	//DOG
	factory.loadDragonBonesData("./Assets/Animation/dogAnim/dogAnim_ske.json");
	factory.loadTextureAtlasData("./Assets/Animation/dogAnim/dogAnim_tex.json", &dogAnim);

	//BISHOP
	factory.loadDragonBonesData("./Assets/Animation/bishopAnim/bishopAnim_ske.json");
	factory.loadTextureAtlasData("./Assets/Animation/bishopAnim/bishopAnim_tex.json", &bishopAnim);

	//BOSS
	factory.loadDragonBonesData("./Assets/Animation/bossAnim/bossAnim_ske.json");
	factory.loadTextureAtlasData("./Assets/Animation/bossAnim/bossAnim_tex.json", &bossAnim);
}

GlobalFactory& GlobalFactory::Instance()
{
	static GlobalFactory gFactory;
	return gFactory;
}
