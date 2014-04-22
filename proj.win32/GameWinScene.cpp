#include "GameWinScene.h"
#include "Config.h"

bool GameWinScene::init(){
	if (!CCScene::init())
		return false;
	CCLayer* layer = CCLayer::create();
	CCSprite* gameWinBg = CCSprite::create("gamewin.png");
	gameWinBg->setScaleX(WINDOW_WIDTH / gameWinBg->getContentSize().width);
	gameWinBg->setScaleY(WINDOW_HEIGHT / gameWinBg->getContentSize().height);
	gameWinBg->setPosition(ccp(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
	layer->addChild(gameWinBg);
	addChild(layer);
	return true;
}