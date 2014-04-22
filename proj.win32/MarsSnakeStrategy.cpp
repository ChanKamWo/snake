#include "MarsSnakeStrategy.h"
#include <cmath>
int MarsSnakeStrategy::getDirection(){
	int nextDir = -1, dis;
	CCPoint nextPos;
	for (int i = 0; i < 4; i++){
		nextPos = (*pSnake->getList().begin())->getPosition() + ccp(dir[i][0], dir[i][1]);
		if (blackBoard->getGrid((int)nextPos.x, (int)nextPos.y) != '_' &&  
			blackBoard->getGrid((int)nextPos.x, (int)nextPos.y) != 'F')continue;
		if (nextDir == -1 || getManhattanDis(foodPos, nextPos) < dis){
			nextDir = i;
			dis = getManhattanDis(foodPos, nextPos);
		}
	}
	if (nextDir == -1)
		nextDir = (*pSnake->getList().begin())->getDirection();
	CCLog("nextDir = %d", nextDir);
	updateBoard(nextDir);
	return nextDir;
}

int MarsSnakeStrategy::getManhattanDis(CCPoint p1, CCPoint p2){
	return (int)(abs(p1.x - p2.x) + abs(p1.y - p2.y));
}