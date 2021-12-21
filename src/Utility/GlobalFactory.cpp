#pragma once
#include "stdafx.h"
#include "GlobalFactory.h"

GlobalFactory::GlobalFactory()
{
	//LOAD TO FACTORY
	//TEXTURES
	heroAnim.loadFromFile("./assets/Animation/heroAnim/heroAnim_tex.png");
	dogAnim.loadFromFile("./assets/Animation/dogAnim/dogAnim_tex.png");
	bishopAnim.loadFromFile("./assets/Animation/bishopAnim/bishopAnim_tex.png");
	bossAnim.loadFromFile("./assets/Animation/bossAnim/bossAnim_tex.png");

	//HERO
	factory.loadDragonBonesData("./assets/Animation/heroAnim/heroAnim_ske.json");
	factory.loadTextureAtlasData("./assets/Animation/heroAnim/heroAnim_tex.json", &heroAnim);

	//DOG
	factory.loadDragonBonesData("./assets/Animation/dogAnim/dogAnim_ske.json");
	factory.loadTextureAtlasData("./assets/Animation/dogAnim/dogAnim_tex.json", &dogAnim);

	//BISHOP
	factory.loadDragonBonesData("./assets/Animation/bishopAnim/bishopAnim_ske.json");
	factory.loadTextureAtlasData("./assets/Animation/bishopAnim/bishopAnim_tex.json", &bishopAnim);

	//BOSS
	factory.loadDragonBonesData("./assets/Animation/bossAnim/bossAnim_ske.json");
	factory.loadTextureAtlasData("./assets/Animation/bossAnim/bossAnim_tex.json", &bossAnim);
}

GlobalFactory& GlobalFactory::Instance()
{
	static GlobalFactory gFactory;
	return gFactory;
}
