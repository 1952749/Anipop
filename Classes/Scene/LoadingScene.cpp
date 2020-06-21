/*
   * 游戏加载界面
   * 功能
       * 预加载资源
*/

#include "Scene/LoadingScene.h"
#include "Scene/HelloWorldScene.h"
#include "Data/Constant.h"

cocos2d::Scene* LoadingScene::createScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto loadingSpr = Sprite::create("Load.png");
	loadingSpr->setPosition(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 2);
	this->addChild(loadingSpr, 1);
	
	return true;
}


void LoadingScene::onEnterTransitionDidFinish()
{
	LoadingAnimation();
}

void LoadingScene::LoadingAnimation()
{
	tranScene();
	SpriteFrameCache* pCache = SpriteFrameCache::getInstance();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Animals/AnimalsList.plist");

	pCache->addSpriteFramesWithFile("Animals\\CatCommon.plist", "Animals\\CatCommon.png");
	Vector< SpriteFrame* > sfme_00 = Vector< SpriteFrame* >(4);
	for (int i = 1; i <= 4; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("CatCommon_%d.png", i));
		sfme_00.pushBack(fname);
	}
	Animation *animation_00 = Animation::createWithSpriteFrames(sfme_00, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_00, "CatCommon");

	pCache->addSpriteFramesWithFile("Animals\\ChookCommon.plist", "Animals\\ChookCommon.png");
	Vector< SpriteFrame* > sfme_01 = Vector< SpriteFrame* >(5);
	for (int i = 1; i <= 5; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("ChookCommon_%d.png", i));
		sfme_01.pushBack(fname);
	}
 	Animation *animation_01 = Animation::createWithSpriteFrames(sfme_01, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_01, "ChookCommon");

	pCache->addSpriteFramesWithFile("Animals\\FoxCommon.plist", "Animals\\FoxCommon.png");
	Vector< SpriteFrame* > sfme_02 = Vector< SpriteFrame* >(7);
	for (int i = 1; i <= 7; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("FoxCommon_%d.png", i));
		sfme_02.pushBack(fname);
	}
	Animation *animation_02 = Animation::createWithSpriteFrames(sfme_02, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_02, "FoxCommon");

	pCache->addSpriteFramesWithFile("Animals\\FrogCommon.plist", "Animals\\FrogCommon.png");
	Vector< SpriteFrame* > sfme_03 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("FrogCommon_%d.png", i));
		sfme_03.pushBack(fname);
	}
	Animation *animation_03 = Animation::createWithSpriteFrames(sfme_03, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_03, "FrogCommon");

	pCache->addSpriteFramesWithFile("Animals\\HippoCommon.plist", "Animals\\HippoCommon.png");
	Vector< SpriteFrame* > sfme_04 = Vector< SpriteFrame* >(4);
	for (int i = 1; i <= 4; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("HippoCommon_%d.png", i));
		sfme_04.pushBack(fname);
	}
	Animation *animation_04 = Animation::createWithSpriteFrames(sfme_04, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_04, "HippoCommon");

	pCache->addSpriteFramesWithFile("Animals\\CatHorizontal.plist", "Animals\\CatHorizontal.png");
	Vector< SpriteFrame* > sfme_05 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("CatHorizontal_%d.png", i));
		sfme_05.pushBack(fname);
	}
	Animation *animation_05= Animation::createWithSpriteFrames(sfme_05, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_05, "CatHorizontal");

	pCache->addSpriteFramesWithFile("Animals\\ChookHorizontal.plist", "Animals\\ChookHorizontal.png");
	Vector< SpriteFrame* > sfme_06 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("ChookHorizontal_%d.png", i));
		sfme_06.pushBack(fname);
	}
	Animation *animation_06 = Animation::createWithSpriteFrames(sfme_06, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_06, "ChookHorizontal");

	pCache->addSpriteFramesWithFile("Animals\\FoxHorizontal.plist", "Animals\\FoxHorizontal.png");
	Vector< SpriteFrame* > sfme_07 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("FoxHorizontal_%d.png", i));
		sfme_07.pushBack(fname);
	}
	Animation *animation_07 = Animation::createWithSpriteFrames(sfme_07, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_07, "FoxHorizontal");

	pCache->addSpriteFramesWithFile("Animals\\FrogHorizontal.plist", "Animals\\FrogHorizontal.png");
	Vector< SpriteFrame* > sfme_08 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("FrogHorizontal_%d.png", i));
		sfme_08.pushBack(fname);
	}
	Animation *animation_08 = Animation::createWithSpriteFrames(sfme_08, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_08, "FrogHorizontal");


	pCache->addSpriteFramesWithFile("Animals\\HippoHorizontal.plist", "Animals\\HippoHorizontal.png");
	Vector< SpriteFrame* > sfme_09 = Vector< SpriteFrame* >(2);
	for (int i = 1; i <= 2; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("HippoHorizontal_%d.png", i));
		sfme_09.pushBack(fname);
	}
	Animation *animation_09 = Animation::createWithSpriteFrames(sfme_09, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_09, "HippoHorizontal");

	pCache->addSpriteFramesWithFile("Animals/CatVertical.plist", "Animals/CatVertical.png");
	Vector< SpriteFrame* > sfme_10 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("CatVertical_%d.png", i));
		sfme_10.pushBack(fname);
	}
	Animation *animation_10 = Animation::createWithSpriteFrames(sfme_10, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_10, "CatVertical");

	pCache->addSpriteFramesWithFile("Animals\\ChookVertical.plist", "Animals\\ChookVertical.png");
	Vector< SpriteFrame* > sfme_11 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("ChookVertical_%d.png", i));
		sfme_11.pushBack(fname);
	}
	Animation *animation_11 = Animation::createWithSpriteFrames(sfme_11, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_11, "ChookVertical");

	pCache->addSpriteFramesWithFile("Animals\\FoxVertical.plist", "Animals\\FoxVertical.png");
	Vector< SpriteFrame* > sfme_12 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("FoxVertical_%d.png", i));
		sfme_12.pushBack(fname);
	}
	Animation *animation_12 = Animation::createWithSpriteFrames(sfme_12, 0.2f);
	Animate* animate_12 = Animate::create(animation_12);
	AnimationCache::getInstance()->addAnimation(animation_12, "FoxVertical");

	pCache->addSpriteFramesWithFile("Animals\\FrogVertical.plist", "Animals\\FrogVertical.png");
	Vector< SpriteFrame* > sfme_13 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("FrogVertical_%d.png", i));
		sfme_13.pushBack(fname);
	}
	Animation *animation_13 = Animation::createWithSpriteFrames(sfme_13, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_13, "FrogVertical");

	pCache->addSpriteFramesWithFile("Animals\\HippoVertical.plist", "Animals\\HippoVertical.png");
	Vector< SpriteFrame* > sfme_14 = Vector< SpriteFrame* >(2);
	for (int i = 1; i <= 2; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("HippoVertical_%d.png", i));
		sfme_14.pushBack(fname);
	}
	Animation *animation_14 = Animation::createWithSpriteFrames(sfme_14, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_14, "HippoVertical");

	pCache->addSpriteFramesWithFile("Animals\\CatBomb.plist", "Animals\\CatBomb.png");
	Vector< SpriteFrame* > sfme_15 = Vector< SpriteFrame* >(6);
	for (int i = 1; i <= 6; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("CatBomb_%d.png", i));
		sfme_15.pushBack(fname);
	}
	Animation *animation_15 = Animation::createWithSpriteFrames(sfme_15, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_15, "CatBomb");

	pCache->addSpriteFramesWithFile("Animals\\ChookBomb.plist", "Animals\\ChookBomb.png");
	Vector< SpriteFrame* > sfme_16 = Vector< SpriteFrame* >(5);
	for (int i = 1; i <= 5; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("ChookBomb_%d.png", i));
		sfme_16.pushBack(fname);
	}
	Animation *animation_16 = Animation::createWithSpriteFrames(sfme_16, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_16, "ChookBomb");

	pCache->addSpriteFramesWithFile("Animals\\FoxBomb.plist", "Animals\\FoxBomb.png");
	Vector< SpriteFrame* > sfme_17 = Vector< SpriteFrame* >(5);
	for (int i = 1; i <= 5; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("FoxBomb_%d.png", i));
		sfme_17.pushBack(fname);
	}
	Animation *animation_17 = Animation::createWithSpriteFrames(sfme_17, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_17, "FoxBomb");

	pCache->addSpriteFramesWithFile("Animals\\FrogBomb.plist", "Animals\\FrogBomb.png");
	Vector< SpriteFrame* > sfme_18 = Vector< SpriteFrame* >(2);
	for (int i = 1; i <= 2; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("FrogBomb_%d.png", i));
		sfme_18.pushBack(fname);
	}
	Animation *animation_18 = Animation::createWithSpriteFrames(sfme_18, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_18, "FrogBomb");
	
	pCache->addSpriteFramesWithFile("Animals\\HippoBomb.plist", "Animals\\HippoBomb.png");
	Vector< SpriteFrame* > sfme_19 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("HippoBomb_%d.png", i));
		sfme_19.pushBack(fname);
	}
	Animation *animation_19 = Animation::createWithSpriteFrames(sfme_19, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_19, "HippoBomb");

	pCache->addSpriteFramesWithFile("Animals\\SuperBird.plist", "Animals\\SuperBird.png");
	Vector< SpriteFrame* > sfme_20 = Vector< SpriteFrame* >(9);
	for (int i = 1; i <= 9; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("SuperBird_%d.png", i));
		sfme_20.pushBack(fname);
	}
	Animation *animation_20 = Animation::createWithSpriteFrames(sfme_20, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_20, "SuperBird");

	pCache->addSpriteFramesWithFile("Animals\\DSuperBird.plist", "Animals\\DSuperBird.png");
	Vector< SpriteFrame* > sfme_21 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("DSuperBird_%d.png", i));
		sfme_21.pushBack(fname);
	}
	Animation *animation_21 = Animation::createWithSpriteFrames(sfme_21, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_21, "DSuperBird");

	pCache->addSpriteFramesWithFile("PlayGame\\Ice.plist", "PlayGame\\Ice.png");
	Vector< SpriteFrame* > sfme_22 = Vector< SpriteFrame* >(3);
	for (int i = 1; i <= 3; i++)
	{
		SpriteFrame* fname = pCache->spriteFrameByName(StringUtils::format("Ice_%d.png", i));
		sfme_22.pushBack(fname);
	}
	Animation *animation_22 = Animation::createWithSpriteFrames(sfme_22, 0.2f);
	AnimationCache::getInstance()->addAnimation(animation_22, "Ice");

}

void LoadingScene::tranScene()
{
	auto call_function = CallFunc::create
	([] {Director::getInstance()->replaceScene(HelloWorld::createScene()); });
	this->runAction(call_function);
}


