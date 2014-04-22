#ifndef MOVE_STRATEGY_H
#define MOVE_STRATEGY_H

#include "BlackBoard.h"
#include "cocos2d.h"
#include "Config.h"
#include "Snake.h"
USING_NS_CC;
class MoveStrategy{
protected:
	BlackBoard<MAP_MAX_X, MAP_MAX_Y>* blackBoard;
	CCPoint foodPos;
	Snake *pSnake;
	void updateBoard(int& nextDir);
public:
	MoveStrategy(BlackBoard<MAP_MAX_X, MAP_MAX_Y>* bb, Snake* pSn) :
		blackBoard(bb), pSnake(pSn){}
	virtual int getDirection() = 0;
};

#endif