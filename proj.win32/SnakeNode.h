#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

#include "cocos2d.h"
#include "Map.h"
USING_NS_CC;

class SnakeNode{
private:
	CCPoint position;
	int direction;
	CCSprite *nodeSprite;
public:
	SnakeNode(CCPoint p, char snakeType, int typeId, int direction = 0);
	void setPosition(CCPoint);
	CCPoint getPosition()const{return position;};
	void setDirection(int direction);
	int getDirection(){ return direction; }
	CCSprite* getNodeSprite()const{return nodeSprite;};
};

#endif