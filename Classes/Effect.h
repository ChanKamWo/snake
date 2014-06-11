#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Snake.h"

class Effect : public Ref
{
protected:

    Snake* targetSnake;

    float speedAddtion;

    volatile float scoreCut;

public:

    virtual void work( Snake* snake ) = 0;

};
#endif
