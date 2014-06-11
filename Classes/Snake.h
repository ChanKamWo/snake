#ifndef SNAKE_H
#define SNAKE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "MoveStrategy.h"
#include "Direction.h"
#include "SnakeBodyNode.h"
#include "Effect.h"

#include "cocos2d.h"
USING_NS_CC;

class Snake : public Sprite
{
private:
    Direction direction;

    float speed;

    int score;

    int length;

    std::list<SnakeBodyNode*>* bodyNodes;

public:
    bool init();

    void move();

    void injectEffect( Effect* effect );

    CREATE_FUNC( Snake );
};
#endif
