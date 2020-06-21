#pragma once
#ifndef _Dialog_H_
#define _Dialog_H_

#include "cocos2d.h"

USING_NS_CC;

class Dialog :public Layer
{
public:

	Size m_size;
	
	Dialog();
	
	~Dialog();
	
	static Scene* createScene();
	
	virtual bool init();
	
	//添加菜单按钮
	bool addButton(const char* normalImage, const char* selectedImage,const char* button_title, int tag, Vec2 position);
	
	bool addButton(const char* normalImage, const char* selectedImage, int tag, Vec2 position);
	
	//设置回调函数
	void setCallbackFunc(CCObject* target, SEL_CallFuncN callfun);
	
	//设置背景图
	void setBackground(const char* backgroundImage);
	
	//按钮
	void  ButtonCallback(Ref* sender);

	//重写onEnter()函数
	virtual void onEnter();
	
	virtual void onExit();

	CCObject* m_callbackListener;
	
	SEL_CallFuncN m_callback;

	CREATE_FUNC(Dialog);

private:
	
	Menu* menu;
	
	Vector<Node*> node;
	
	const char* m_title;
	
	const char* m_content;
	
	int m_title_fontSize;
	
	int m_content_fontSize;
	
	Sprite* sprite_m;
	
	Sprite* background;
	
	Size visiableSize;
	
	const char* backgroundImage;
};

#endif //_DIALOG_H_
