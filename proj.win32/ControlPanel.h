#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H

#include "cocos2d.h"
#include <algorithm>
using std::pair;

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)   
#include <windows.h>
#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code) & 0x8000 ? 1 : 0)
#define KEY_UP(vk_code) (GetAsyncKeyState(vk_code) & 0x8000 ? 0 : 1)
#endif

USING_NS_CC;
class ControlPanel : public CCLayer{
private:
	int key;
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)   
	void detectKeyBoard(float interval);
#else
	void leftDown(CCObject* pSender);
	void rightDown(CCObject* pSender);
#endif

public:
	CREATE_FUNC(ControlPanel);
	bool init();
	int getNextDirection();
};

#endif