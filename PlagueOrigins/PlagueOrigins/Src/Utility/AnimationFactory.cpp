#include "stdafx.h"
#include "AnimationFactory.h"

AnimationFactory::AnimationFactory()
{
    //LOAD TO FACTORY
	//TEXTURES
	heroAnim.loadFromFile("./Assets/Animation/heroAnim/heroAnim_tex.png");
	dogAnim.loadFromFile("./Assets/Animation/dogAnim/dogAnim_tex.png");
	bishopAnim.loadFromFile("./Assets/Animation/bishopAnim/bishopAnim_tex.png");

	//HERO
	factory.loadDragonBonesData("./Assets/Animation/heroAnim/heroAnim_ske.json");
	factory.loadTextureAtlasData("./Assets/Animation/heroAnim/heroAnim_tex.json", &heroAnim);

	//DOG
	factory.loadDragonBonesData("./Assets/Animation/dogAnim/dogAnim_ske.json");
	factory.loadTextureAtlasData("./Assets/Animation/dogAnim/dogAnim_tex.json", &dogAnim);

	//BISHOP
	factory.loadDragonBonesData("./Assets/Animation/bishopAnim/bishopAnim_ske.json");
	factory.loadTextureAtlasData("./Assets/Animation/bishopAnim/bishopAnim_tex.json", &bishopAnim);
}

void AnimationFactory::updateInternal(const float& dt)
{
	factory.update(dt);
}