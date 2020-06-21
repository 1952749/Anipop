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
	
	//��Ӳ˵���ť
	bool addButton(const char* normalImage, const char* selectedImage,const char* button_title, int tag, Vec2 position);
	
	bool addButton(const char* normalImage, const char* selectedImage, int tag, Vec2 position);
	
	//���ûص�����
	void setCallbackFunc(CCObject* target, SEL_CallFuncN callfun);
	
	//���ñ���ͼ
	void setBackground(const char* backgroundImage);
	
	//��ť
	void  ButtonCallback(Ref* sender);

	//��дonEnter()����
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
