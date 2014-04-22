#ifndef EARTH_SNAKE_STRATEGY_H
#define EARTH_SNAKE_STRATEGY_H

#include "MoveStrategy.h"
#include "Snake.h"
#include "cocos2d.h"
#include "BlackBoard.h"
#include "Config.h"

USING_NS_CC;
class EarthSnakeStrategy : public MoveStrategy{
public:
	EarthSnakeStrategy(BlackBoard<MAP_MAX_X, MAP_MAX_Y>* bb, Snake* pSn) :
		MoveStrategy(bb, pSn){}
	int getDirection();
};

#endif