#ifndef FOOD_H
#define FOOD_H

#include "cocos2d.h"

USING_NS_CC;
class Food{
private:
	CCPoint position;
	CCSprite *sprite;
public:
	Food();
	CCSprite* getSprite(){ return sprite; }
	void setTiledPos(CCPoint pos);
	CCPoint getTiledPos()const{return position;}
};

#endif