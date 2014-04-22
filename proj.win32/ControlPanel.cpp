#include "ControlPanel.h"
#include "Config.h"

bool ControlPanel::init(){
	if (!CCLayer::init())
		return false;
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)   
	schedule(schedule_selector(ControlPanel::detectKeyBoard), 0.1);
#else
	CCMenuItem *leftMenuItem = CCMenuItemImage::create("larrow.png", "larrow.png", this, menu_selector(ControlPanel::leftDown));
	CCMenuItem *rightMenuItem = CCMenuItemImage::create("rarrow.png", "rarrow.png", this, menu_selector(ControlPanel::rightDown));
	CCMenu *menu = CCMenu::create(leftMenuItem, rightMenuItem, NULL);
	leftMenuItem->setContentSize(CCSizeMake(leftMenuItem->getContentSize().width / 2, leftMenuItem->getContentSize().height));
	rightMenuItem->setContentSize(CCSizeMake(rightMenuItem->getContentSize().width / 2, rightMenuItem->getContentSize().height));
	leftMenuItem->setScaleX(0.5);
	rightMenuItem->setScaleX(0.5);
	leftMenuItem->setPosition(ccp(leftMenuItem->getContentSize().width / 2, WINDOW_HEIGHT / 2));
	rightMenuItem->setPosition(ccp(WINDOW_WIDTH - leftMenuItem->getContentSize().width / 2, WINDOW_HEIGHT / 2));
	menu->setPosition(ccp(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
	addChild(menu);
	menu->setAnchorPoint(ccp(0, 0));
	menu->setPosition(ccp(0,0));
#endif
	return true;
}

void ControlPanel::detectKeyBoard(float interval){
	if (KEY_DOWN(VK_UP))
		key = 3;
	else if (KEY_DOWN(VK_DOWN))
		key = 1;
	else if (KEY_DOWN(VK_LEFT))
		key = 2;
	else if (KEY_DOWN(VK_RIGHT))
		key = 0;
}

int ControlPanel::getNextDirection(){
	int temp = key;
	key = -1;
	return temp;
}

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)   
void ControlPanel::leftDown(CCObject* pSender){
	key = 3;
}

void ControlPanel::rightDown(CCObject* pSender){
	key = 1;
}
#endif