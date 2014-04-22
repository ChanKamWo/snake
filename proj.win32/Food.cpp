#include "Food.h"
#include "Map.h"

Food::Food(){
	sprite = CCSprite::create("food.png");
}

void Food::setTiledPos(CCPoint pos){
	position = pos;
	sprite->setPosition(Map::tiledPositionToCoordGL(position));
}

