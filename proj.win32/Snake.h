#ifndef SNAKE_H
#define SNAKE_H
#include "cocos2d.h"
#include <list>
#include "SnakeNode.h"
using std::list;
USING_NS_CC;
class Snake{
private:
	int direction;
	char type;
	list<SnakeNode*> nodes;
public:
	Snake(int initDir, char sType);//E for Earth snake, M for Mars snake
	list<SnakeNode*>& getList(){ return nodes; }
	void move(int nextDir);
	SnakeNode* addNode();
	char getType(){ return type; }
};

#endif