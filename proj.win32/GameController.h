#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "cocos2d.h"
#include <string>

using std::string;
USING_NS_CC;
class GameController{
public:
	GameController();
	void launchGame();
	void exitGame();
	void startGame();
	void pauseGame();
	void endGame();
	static GameController* getInstance();
	int getNextDirection();
	void updateScore(string text);

private:
	static GameController* pGameController;
	CCScene *gameScene, *gameOverScene;
};

#endif