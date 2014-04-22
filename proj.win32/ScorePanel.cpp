#include "ScorePanel.h"
#include "Config.h"

bool ScorePanel::init(){
	if (!CCLayer::init())
		return false;
	label = CCLabelTTF::create();
	addChild(label);
	return true;
}

void ScorePanel::updateText(string text){
	label->setString(text.c_str());
	label->setPosition(ccp(WINDOW_WIDTH / 2, WINDOW_HEIGHT - label->getContentSize().height / 2));
}