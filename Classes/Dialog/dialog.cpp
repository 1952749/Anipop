/*
   * 弹出窗口相关函数
   * 功能
        * 背景
		* 按钮
		* 动态弹窗
*/

#include "Dialog/dialog.h"
#include "cocos2d.h"

USING_NS_CC;

Dialog::Dialog() :
	m_title(NULL),
	m_content(NULL),
	m_content_fontSize(0),
	m_title_fontSize(0),
	m_callback(NULL),
	m_callbackListener(NULL),
	m_size(0, 0)
{
}

Dialog::~Dialog()
{
	CC_SAFE_RELEASE(background);
	CC_SAFE_RELEASE(menu);
}

Scene* Dialog::createScene()
{
	auto scene = Scene::create();
	auto layer = Dialog::create();
	scene->addChild(layer);
	return scene;
}

bool Dialog::init()
{
	if (!Layer::init()) {
		return false;
	}
	menu = Menu::create();
	node = Vector<Node*>();
	visiableSize = Director::getInstance()->getVisibleSize();
	return true;
}

bool Dialog::addButton(const char* normalImage, const char* selectedImage, const char* button_title, int tag, Vec2 position)
{
	// 创建图片菜单按钮
	MenuItemImage* menuImage = MenuItemImage::create(normalImage, selectedImage, this, menu_selector(Dialog::ButtonCallback));
	menuImage->setTag(tag);
	menuImage->setPosition(position);

	// 添加文字说明并设置位置
	CCSize imenu = menuImage->getContentSize();
	CCLabelTTF* ttf = CCLabelTTF::create(button_title, "", 20);
	ttf->setColor(ccc3(0, 0, 0));
	ttf->setPosition(ccp(imenu.width / 2, imenu.height / 2));
	menuImage->addChild(ttf);
	Menu* menu = Menu::create(menuImage, NULL);
	node.pushBack(menu);
	return true;
}

bool Dialog::addButton(const char* normalImage, const char* selectedImage, int tag, Vec2 position)
{
	
	MenuItemImage* menuImage = MenuItemImage::create(normalImage, selectedImage, this, menu_selector(Dialog::ButtonCallback));
	menuImage->setTag(tag);
	Menu* menu = Menu::create(menuImage, NULL);
	menu->setPosition(position);
	node.pushBack(menu);
	return true;
}

void Dialog::setCallbackFunc(CCObject* target, SEL_CallFuncN callfun)
{
	m_callbackListener = target;
	m_callback = callfun;
}

void Dialog::setBackground(const char* backgroundImage)
{

	this->backgroundImage = backgroundImage;
}

void Dialog::ButtonCallback(Ref* sender)
{

	Node* node = dynamic_cast<Node*>(sender);
	if (m_callback && m_callbackListener) {
		(m_callbackListener->*m_callback)(node);//回调
	}
	this->removeFromParentAndCleanup(true);
}

void Dialog::onEnter()
{
	Layer::onEnter();
	background = Sprite::create(backgroundImage);
	background->setPosition(visiableSize.width / 2, visiableSize.height / 2);
	background->setScale(1.0f);
	addChild(background, 1);
	//设置对话框的大小为背景图像的大小
	m_size = background->getContentSize();

	for (const auto& node2 : node)
	{
		addChild(node2, 2);
	}
	
	//动态
	FiniteTimeAction* action = Sequence::create(
		ScaleTo::create(0.2, 0.2),
		ScaleTo::create(0.4, 0.4),
		ScaleTo::create(0.6, 0.6),
		ScaleTo::create(0.8, 0.8), NULL);
	this->runAction(action);
}

void Dialog::onExit()
{
	Layer::onExit();
}

