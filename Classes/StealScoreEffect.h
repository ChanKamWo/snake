#ifndef STEAL_SCORE_EFFECT_H
#define STEAL_SCORE_EFFECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Effect.h"
#include "Snake.h"

class StealScoreEffect : public Effect
{
public:
    StealScoreEffect();

    void work( Snake* snake );

};
#endif
