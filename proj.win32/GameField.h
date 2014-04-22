#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "cocos2d.h"
#include "Map.h"
#include "Snake.h"
#include "Food.h"
#include "BlackBoard.h"
#include "MoveStrategy.h"
USING_NS_CC;
class GameField : public CCLayer{
private:
	Map *map;
	BlackBoard<MAP_MAX_X, MAP_MAX_Y> blackBoard;
	Snake *marsSnake, *earthSnake;
	MoveStrategy *marsStrategy, *earthStrategy;
	Food *food;
	void initMarsSnake();
	void initEarthSnake();
	void initMap();
	void genFood();
	void moveFood();
	void addSnakeToBoard(Snake* pSnake);
	void addSnakeToField(Snake* pSnake);
	void moveMarsSnake(float interval);
	void moveEarthSnake(float interval);
public:
	bool init();
	void startGame();
	CREATE_FUNC(GameField);
};

#endif