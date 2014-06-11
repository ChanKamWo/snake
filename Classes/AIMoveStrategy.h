#ifndef A_I_MOVE_STRATEGY_H
#define A_I_MOVE_STRATEGY_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "MoveStrategy.h"

class AIMoveStrategy : public MoveStrategy
{
public:
    void move( std::list<SnakeBodyNode*> nodes );

};
#endif
