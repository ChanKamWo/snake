#include "GameScene.h"

bool GameScene::init(){
	if (!CCScene::init())
		return false;
	gameField = GameField::create();
	addChild(gameField);
	scorePanel = ScorePanel::create();
	addChild(scorePanel);
	controlPanel = ControlPanel::create();
	addChild(controlPanel);
	return true;
}

void GameScene::updateText(string text){
	scorePanel->updateText(text);
}

int GameScene::getNextDirection(){
	return controlPanel->getNextDirection();
}