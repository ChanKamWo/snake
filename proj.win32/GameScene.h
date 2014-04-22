#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "GameField.h"
#include "cocos2d.h"
#include "ScorePanel.h"
#include "ControlPanel.h"
#include <algorithm>
using std::pair;
USING_NS_CC;
class GameScene : public CCScene{
private:
	GameField *gameField;
	ControlPanel *controlPanel;
	ScorePanel *scorePanel;
public:
	bool init();
	void updateText(string text);
	int getNextDirection();
	CREATE_FUNC(GameScene);
};

#endif