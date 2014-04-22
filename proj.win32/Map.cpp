#include "Map.h"

Map::Map(){
	map = CCTMXTiledMap::create("maps/lvl1.tmx");
}

CCTMXTiledMap* Map::getTiledMap()const{
	return map;
}

CCPoint Map::convertCoordGLToTile(CCPoint p)
{
	int x = (int)p.x / TILED_WIDTH;
	int y = (int)(((visibleOrigin.y) * TILED_HEIGHT) - p.y) / TILED_HEIGHT;
	return CCPointMake((float)x,(float)y);
}


CCPoint Map::tiledPositionToCoordGL(CCPoint p)
{
	return ccp(p.x*TILED_WIDTH + TILED_WIDTH/2.0 ,WINDOW_HEIGHT - p.y*TILED_HEIGHT - TILED_HEIGHT/2.0);
}

int Map::getTileType(CCPoint p) const
{
	int value = map->layerNamed("block")->tileGIDAt(p);
	return value;
}