#ifndef PLAY_SCENE_H
#define PLAY_SCENE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Snake.h"
#include "cocos2d.h"
USING_NS_CC;

class PlayScene : public Scene
{
private:
    Snake* earthSnake;

    Snake* marsSnake;


public:
    bool init();

};
#endif
