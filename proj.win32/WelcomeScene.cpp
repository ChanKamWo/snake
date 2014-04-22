#include "WelcomeScene.h"
#include "Config.h"
#include "GameController.h"

bool WelcomeScene::init(){
	if (!CCLayer::init())
		return false;
	CCSprite* welcomeBg = CCSprite::create("welcome.jpg");
	welcomeBg->setScaleX(WINDOW_WIDTH / welcomeBg->getContentSize().width);
	welcomeBg->setScaleY(WINDOW_HEIGHT / welcomeBg->getContentSize().height);
	welcomeBg->setPosition(ccp(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
	addChild(welcomeBg, 0);

	CCMenuItem *startMenuItem = CCMenuItemImage::create("startgame.png", "startgame.png", this, menu_selector(WelcomeScene::startMenuCallback));
	CCMenuItem *endMenuItem = CCMenuItemImage::create("exitgame.png", "exitgame.png", this, menu_selector(WelcomeScene::endMenuCallback));
	CCMenu *menu = CCMenu::create(startMenuItem, endMenuItem, NULL);
	startMenuItem->setScale(0.6);
	endMenuItem->setScale(0.6);
	menu->alignItemsHorizontally();
	menu->setPosition(ccp(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 5 * 2));

	addChild(menu, 1);

	return true;
}

CCScene* WelcomeScene::scene(){
	CCScene* pScene = CCScene::create();
	WelcomeScene *layer = WelcomeScene::create();
	pScene->addChild(layer);
	return pScene;
}

void WelcomeScene::startMenuCallback(CCObject * pSender){
	GameController::getInstance()->startGame();
}

void WelcomeScene::endMenuCallback(CCObject* pSender){
	GameController::getInstance()->exitGame();
}