#include "HelloWorldScene.h"
#include "SelectLevelScene.h"
#include"SetVolumeScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//BGM
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (!audio->isBackgroundMusicPlaying())
	{
		audio->playBackgroundMusic("Audio/WorldBGM.mp3", true);
	}
	
	auto startItem = MenuItemImage::create(
		"HelloWorld/StartNormal.png",
		"HelloWorld/StartSelected.png",
		CC_CALLBACK_1(HelloWorld::menuStartCallBack, this));

	if (startItem == nullptr ||
		startItem->getContentSize().width <= 0 ||
		startItem->getContentSize().height <= 0)
	{
		problemLoading("'StartNormal.png' and 'StartSelected.png'");
	}
	else
	{
		startItem->setPosition(Vec2(150.0, 250.0));
	}

	auto closeItem = MenuItemImage::create(
		"HelloWorld/CloseNormal.png",
		"HelloWorld/CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallBack, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		closeItem->setPosition(Vec2(150.0, 150.0));
	}

	auto setItem = MenuItemImage::create(
		"HelloWorld/SettingNormal.png",
		"HelloWorld/SettingSelected.png",
		CC_CALLBACK_1(HelloWorld::menuSetCallback, this));

	float x = origin.x + setItem->getContentSize().width / 2;
	float y = origin.y + visibleSize.height - setItem->getContentSize().height / 2;
	setItem->setPosition(Vec2(x, y));

	auto menu = Menu::create(startItem, closeItem, setItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	//ÓÎÏ·±³¾°
	auto sprite = Sprite::create("HelloWorld/WorldBG.jpg");
	if (sprite == nullptr)
	{
		problemLoading("'HelloWorld/WorldBG.jpg'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}

    return true;
}

void HelloWorld::menuStartCallBack(cocos2d::Ref * pSender)
{
	auto nextScene = SelectLevel::create();
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(1.0f / 60, nextScene));
	MenuItem *item = (MenuItem*)pSender;

	log("Touch Start Menu Item %p", item);
}

void HelloWorld::menuCloseCallBack(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}


void HelloWorld::menuSetCallback(Ref *pSender)
{
	auto nextScene = SetVolume::create();
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(1.0f / 60, nextScene));
	MenuItem *item = (MenuItem*)pSender;

	log("Touch Hello Menu Item %p", item);
}
