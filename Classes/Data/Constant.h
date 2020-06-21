/*
    * 游戏中的定义
*/


#pragma once
#ifndef _CONSTANT_H__
#define _CONSTANT_H__

//屏幕的宽和高
#define GAME_SCREEN_WIDTH 1280
#define GAME_SCREEN_HEIGHT 800

//地图的最大边长
#define MAX_LENGTH 7

//每个方块的边长大小
#define BLOCK_SIZE 90

// 小动物精灵种类个数
#define TOTAL_ANI 5

#define TOTAL_PRO 5

// 音乐音效
#include "SimpleAudioEngine.h"
#define SOUND_KEY "sound_key"
#define MUSIC_KEY "music_key"

// 分数存储
#define userDefault CCUserDefault::sharedUserDefault()

// 精灵的状态，Horizontal表示横向消除一行，Vertical表示纵向消除一列
enum AnimalsState 
{
	COMMON = 0,
	HORIZONTAL,
	VERTICAL,
	BOMB,
	SUPERBIRD
};

enum BlockState
{
	EMPTY = 0,
	ANIMAL,
	ICE
};

enum PropType
{
	RESET = 0,
	ADDTHREE,
	ADDFIVE,
	ADDMAGIC,
	HAMMER
};

#define CAT 0

// 获取精灵 普通
static const char *Common[TOTAL_ANI] = 
{
	"Cat.png",
	"Chook.png",
	"Fox.png",
	"Frog.png",
	"Hippo.png"
};

static const char *CommonAni[TOTAL_ANI] = 
{
	"CatCommon",
	"ChookCommon",
	"FoxCommon",
	"FrogCommon",
	"HippoCommon",
};

static const char *HorizontalAni[TOTAL_ANI] =
{
	"CatHorizontal",
	"ChookHorizontal",
	"FoxHorizontal",
	"FrogHorizontal",
	"HippoHorizontal"
};
static const char *VerticalAni[TOTAL_ANI] =
{
	"CatVertical",
	"ChookVertical",
	"FoxVertical",
	"FrogVertical",
	"HippoVertical"
};

static const char *BombAni[TOTAL_ANI] = 
{
	"CatBomb",
	"ChookBomb",
	"FoxBomb",
	"FrogBomb",
	"HippoBomb"
};

static const char *PropPics[TOTAL_PRO] =
{
	"Props/Reset.png",
	"Props/AddThree.png",
	"Props/AddFive.png",
	"Props/AddMagic.png",
	"Props/Hammer.png"
};

static const char *SelPropPics[TOTAL_PRO] =
{
	"Props/SelReset.png",
	"Props/SelAddThree.png",
	"Props/SelAddFive.png",
	"Props/SelAddMagic.png",
	"Props/SelHammer.png"
};
#endif 
