#ifndef TURN_EFFECT_H
#define TURN_EFFECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Effect.h"
#include "Snake.h"

class TurnEffect : public Effect
{
public:
    TurnEffect();

    void work( Snake* snake );

};
#endif
