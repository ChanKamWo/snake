#include "GameField.h"
#include "RandomNum.h"
#include "MarsSnakeStrategy.h"
#include "GameController.h"
#include "EarthSnakeStrategy.h"
#include <ctime>

bool GameField::init(){
	if (!CCLayer::init())
		return false;
	initMap();
	initEarthSnake();
	initMarsSnake();
	startGame();
	return true;
}

void GameField::initMap(){
	map = new Map();
	addChild(map->getTiledMap());
	for(int i = 0;i < MAP_MAX_X;i++){
		for(int j = 0;j < MAP_MAX_Y;j++){
			int gid = map->getTiledMap()->layerNamed("obstacles")->tileGIDAt(ccp(i, j));
			if (gid == 0){
				blackBoard.setGrid(i, j, '_');
			}
			else{
				blackBoard.setGrid(i, j, 'B');
			}
		}
	}
}

void GameField::initMarsSnake(){
	marsSnake = new Snake(2, 'M');
	marsStrategy = new MarsSnakeStrategy(&blackBoard, marsSnake);
	addSnakeToField(marsSnake);
	addSnakeToBoard(marsSnake);
}

void GameField::initEarthSnake(){
	earthSnake = new Snake(0, 'E');
	earthStrategy = new EarthSnakeStrategy(&blackBoard, earthSnake);
	addSnakeToField(earthSnake);
	addSnakeToBoard(earthSnake);
}

void GameField::addSnakeToField(Snake* pSnake){
	for (list<SnakeNode*>::const_iterator iter = pSnake->getList().begin();
		iter != pSnake->getList().end(); iter++){
		addChild((*iter)->getNodeSprite());
	}
}

void GameField::addSnakeToBoard(Snake* pSnake){
	for (list<SnakeNode*>::const_iterator iter = pSnake->getList().begin(); 
		iter != pSnake->getList().end(); iter++){
		blackBoard.setGrid((int)(*iter)->getPosition().x, (int)(*iter)->getPosition().y, 'M');
	}
}

void GameField::startGame(){
	genFood();
	schedule(schedule_selector(GameField::moveMarsSnake), 0.1);
	schedule(schedule_selector(GameField::moveEarthSnake), 0.3);
}

void GameField::moveMarsSnake(float interval){
	((MarsSnakeStrategy*)marsStrategy)->setFoodPos(food->getTiledPos());
	int nextDir = marsStrategy->getDirection();
	if (nextDir < 0){//吃到东西了
		moveFood();
		nextDir += 4;
		addChild(marsSnake->addNode()->getNodeSprite());
	}
	else if (nextDir >= 4){//撞死
		nextDir -= 4;
	//	GameController::getInstance()->endGame();
	}
	marsSnake->move(nextDir);
}

void GameField::moveEarthSnake(float interval){
	int nextDir = earthStrategy->getDirection();
	if (nextDir < 0){//吃到东西了
		moveFood();
		nextDir += 4;
		addChild(earthSnake->addNode()->getNodeSprite());
	}
	else if (nextDir >= 4){//撞死
		nextDir -= 4;
		GameController::getInstance()->endGame();
	}
	earthSnake->move(nextDir);
}
void GameField::genFood(){
	int x, y;
	do{
		x = nrand(MAP_MAX_X);
		y = nrand(MAP_MAX_Y);
	}while(blackBoard.getGrid(x, y) != '_');
	food = new Food();
	x = 7, y = 3;
	food->setTiledPos(ccp(x, y));
	blackBoard.setGrid(x, y, 'F');	
	addChild(food->getSprite());
}

void GameField::moveFood(){
	int x, y;
	do{
		x = nrand(MAP_MAX_X);
		y = nrand(MAP_MAX_Y);
		CCLog("x = %d, y = %d", x, y);
	} while (blackBoard.getGrid(x, y) != '_');
	food->setTiledPos(ccp(x, y));
	blackBoard.setGrid(x, y, 'F');
}