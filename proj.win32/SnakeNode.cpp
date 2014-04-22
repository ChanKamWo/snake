#include "SnakeNode.h"
#include "Config.h"
#include <string>
using std::string;

SnakeNode::SnakeNode(CCPoint p, char snakeType, int typeId, int direction){
	string parts[3] = { "Head.png", "Body.png", "Tail.png" };
	string str = "snakes/";
	str.push_back(snakeType);
	str.append(parts[typeId].c_str());
	nodeSprite = CCSprite::create(str.c_str());
	setPosition(p);
	setDirection(direction);
}

void SnakeNode::setPosition(CCPoint p){
	position = p;
	nodeSprite->setPosition(Map::tiledPositionToCoordGL(p));
}

void SnakeNode::setDirection(int direction){
	this->direction = direction;
	nodeSprite->setRotation(90 * direction);
}