#ifndef CONFIG_H
#define CONFIG_H
#include "cocos2d.h"
#include <cmath>
#define SNAKE_HEAD 0
#define SNAKE_MID_BODY 1
#define SNAKE_TAIL 2
USING_NS_CC;
const CCPoint visibleOrigin = CCPointZero;
const int MAP_MAX_X = 25, MAP_MAX_Y = 15;
const int TILED_WIDTH = 32, TILED_HEIGHT = 32;
const int WINDOW_HEIGHT = 480;
const int WINDOW_WIDTH = 800;
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};//右，下，左，上（TileMap坐标系）
#endif