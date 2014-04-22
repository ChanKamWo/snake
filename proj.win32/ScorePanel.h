#ifndef SCORE_PANEL_H
#define SCORE_PANEL_H

#include <string>
#include "cocos2d.h"
USING_NS_CC;
using std::string;
class ScorePanel : public CCLayer{
private:
	CCLabelTTF *label;
public:
	CREATE_FUNC(ScorePanel);
	bool init();
	void updateText(string text);
};

#endif