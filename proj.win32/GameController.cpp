#include "GameController.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "WelcomeScene.h"

GameController* GameController::pGameController = NULL;

GameController::GameController(){
}

GameController* GameController::getInstance(){
	if (pGameController == NULL)
		pGameController = new GameController();
	return pGameController;
}

void GameController::launchGame(){
	CCDirector::sharedDirector()->runWithScene(WelcomeScene::scene());
}

void GameController::updateScore(string text){
	((GameScene*)gameScene)->updateText(text);
}

void GameController::endGame(){
	gameOverScene = GameOverScene::create();
	CCDirector::sharedDirector()->replaceScene(gameOverScene);
}

void GameController::startGame(){
	gameScene = GameScene::create();
	CCDirector::sharedDirector()->replaceScene(gameScene);
}

void GameController::exitGame(){
	CCDirector::sharedDirector()->end();
}

int GameController::getNextDirection(){
	return ((GameScene*)gameScene)->getNextDirection();
}