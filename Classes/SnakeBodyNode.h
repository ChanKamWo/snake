#ifndef SNAKE_BODY_NODE_H
#define SNAKE_BODY_NODE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Direction.h"
#include "cocos2d.h"
USING_NS_CC;

enum BodyNodeType
{
    HEAD,BODY,TAIL
};

class SnakeBodyNode : public Sprite
{
private:
    Direction direction;

public:
    SnakeBodyNode( BodyNodeType type );

    bool init();

    static SnakeBodyNode* create( BodyNodeType type );
};
#endif
