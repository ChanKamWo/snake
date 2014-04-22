#include "EarthSnakeStrategy.h"
#include "GameController.h"


int EarthSnakeStrategy::getDirection(){
	int nextDir = GameController::getInstance()->getNextDirection();
	int currentDir = (*pSnake->getList().begin())->getDirection();
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)   
	if (nextDir == -1 || nextDir == (currentDir + 2) % 4){
		nextDir = currentDir;
	}
#else
	if(nextDir != -1){
		nextDir = (currentDir + nextDir) % 4;
	}
#endif
	updateBoard(nextDir);
	return nextDir;
}