#ifndef USER_MOVE_STRATEGY_H
#define USER_MOVE_STRATEGY_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "MoveStrategy.h"

class UserMoveStrategy : public MoveStrategy
{
public:
    void move( std::list<SnakeBodyNode*> nodes );

};
#endif
