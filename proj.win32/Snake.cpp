#include "Snake.h"
#include "Config.h"
Snake::Snake(int initDir, char sType):direction(initDir), type(sType){
	switch (sType){
	case 'E':
		nodes.push_back(new SnakeNode(ccp(3, 3), type, SNAKE_HEAD));
		nodes.push_back(new SnakeNode(ccp(2, 3), type, SNAKE_MID_BODY));
		nodes.push_back(new SnakeNode(ccp(1, 3), type, SNAKE_TAIL));
		break;
	case 'M':
		nodes.push_back(new SnakeNode(ccp(19, 12), type, SNAKE_HEAD));
		nodes.push_back(new SnakeNode(ccp(20, 12), type, SNAKE_MID_BODY));
		nodes.push_back(new SnakeNode(ccp(21, 12), type, SNAKE_TAIL));
		break;
	}
}

void Snake::move(int nextDir){
	direction = nextDir;
	list<SnakeNode*>::reverse_iterator iter = nodes.rbegin(), prev = iter;
	int sz = nodes.size();
	for (++iter; iter != nodes.rend(); iter++){
		(*prev)->setPosition((*iter)->getPosition());
		(*prev)->setDirection((*iter)->getDirection());
		prev = iter;
	}
	list<SnakeNode*>::iterator head = nodes.begin();
	(*head)->setPosition((*head)->getPosition() + ccp(dir[nextDir][0], dir[nextDir][1]));
	(*head)->setDirection(nextDir);
}

//must be called before move()
SnakeNode* Snake::addNode(){
	list<SnakeNode*>::iterator last = nodes.end();
	last--;
	SnakeNode* newNode = new SnakeNode((*last)->getPosition(), type, SNAKE_MID_BODY, (*last)->getDirection());
	(*last)->setPosition((*last)->getPosition() - ccp(dir[(*last)->getDirection()][0], dir[(*last)->getDirection()][1]));
	nodes.insert(last, newNode);
	return newNode;
}