#ifndef WELCOME_SCENE_H
#define WELCOME_SCENE_H

#include "cocos2d.h"
USING_NS_CC;
class WelcomeScene : public CCLayer{
public:
	CREATE_FUNC(WelcomeScene);
	bool init();
	void startMenuCallback(CCObject * pSender);
	void endMenuCallback(CCObject * pSender);
	static CCScene* scene();
};

#endif