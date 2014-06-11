#ifndef MOVE_STRATEGY_H
#define MOVE_STRATEGY_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "SnakeBodyNode.h"

class MoveStrategy
{
public:
    virtual void move( std::list<SnakeBodyNode*> nodes ) = 0;

};
#endif
