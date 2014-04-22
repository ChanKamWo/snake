#include "MoveStrategy.h"

//must be called before getDirection() ends
void MoveStrategy::updateBoard(int& nextDir){
	CCPoint nextPos = (*pSnake->getList().begin())->getPosition() + ccp(dir[nextDir][0], dir[nextDir][1]);
	if (blackBoard->getGrid((int)nextPos.x, (int)nextPos.y) == 'F'){
		nextDir -= 4;
	}
	else if (blackBoard->getGrid((int)nextPos.x, (int)nextPos.y) == '_'){
		CCPoint tailPos = (*pSnake->getList().rbegin())->getPosition();
		blackBoard->setGrid((int)tailPos.x, (int)tailPos.y, '_');
	}
	else{//×²ËÀ
		nextDir += 4;
	}
	blackBoard->setGrid((int)nextPos.x, (int)nextPos.y, 'M');
}