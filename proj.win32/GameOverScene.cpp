#include "GameOverScene.h"
#include "Config.h"

bool GameOverScene::init(){
	if (!CCScene::init())
		return false;
	CCLayer* layer = CCLayer::create();
	CCSprite* gameOverBg = CCSprite::create("gameover.png");
	gameOverBg->setScaleX(WINDOW_WIDTH / gameOverBg->getContentSize().width);
	gameOverBg->setScaleY(WINDOW_HEIGHT / gameOverBg->getContentSize().height);
	gameOverBg->setPosition(ccp(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
	layer->addChild(gameOverBg);
	addChild(layer);
	return true;
}