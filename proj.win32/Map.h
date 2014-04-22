#ifndef MAP_H
#define MAP_H

#include "cocos2d.h"
#include "Config.h"
USING_NS_CC;

class Map{
private:
	CCTMXTiledMap *map;

public:
	Map();
	CCSprite* getTileAt(CCPoint p)const;
	CCTMXTiledMap* getTiledMap()const;
	int getTileType(CCPoint p) const;
	static CCPoint convertCoordGLToTile(CCPoint p);
	static CCPoint tiledPositionToCoordGL(CCPoint);
};

#endif