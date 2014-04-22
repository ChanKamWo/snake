#ifndef MARS_SNAKE_STRATEGY_H
#define MARS_SNAKE_STRATEGY_H

#include "MoveStrategy.h"
#include "Snake.h"
#include "cocos2d.h"
#include "BlackBoard.h"
#include "Config.h"
USING_NS_CC;
class MarsSnakeStrategy : public MoveStrategy{
private:
	int getManhattanDis(CCPoint p1, CCPoint p2);
	
public:
	MarsSnakeStrategy(BlackBoard<MAP_MAX_X, MAP_MAX_Y>* bb, Snake* pSn):
		MoveStrategy(bb, pSn){}
	int getDirection();
	void setFoodPos(CCPoint fp){ foodPos = fp; }
};

#endif