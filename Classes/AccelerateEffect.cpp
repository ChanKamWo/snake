#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "AccelerateEffect.h"


AccelerateEffect::AccelerateEffect()
{
    speedAddtion = -0.1f;
    scoreCut = 0;
}

void AccelerateEffect::work( Snake* snake )
{
    targetSnake->injectEffect( this );
}
