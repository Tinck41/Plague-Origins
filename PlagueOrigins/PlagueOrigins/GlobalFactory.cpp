#pragma once
#include "stdafx.h"
#include "GlobalFactory.h"

GlobalFactory::GlobalFactory()
{
	heroAnim.loadFromFile("./Assets/Animation/heroAnim/heroAnim_tex.png");
	dogAnim.loadFromFile("./Assets/Animation/dogAnim/dogAnim_tex.png");

	//HERO
	factory.loadDragonBonesData("./Assets/Animation/heroAnim/heroAnim_ske.json");
	factory.loadTextureAtlasData("./Assets/Animation/heroAnim/heroAnim_tex.json", &heroAnim);

	//DOG
	factory.loadDragonBonesData("./Assets/Animation/dogAnim/dogAnim_ske.json");
	factory.loadTextureAtlasData("./Assets/Animation/dogAnim/dogAnim_tex.json", &dogAnim);
}

GlobalFactory& GlobalFactory::Instance()
{
	static GlobalFactory gFactory;
	return gFactory;
}
