#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "base\CCRef.h"

class GameController : public Ref
{
private:
    static GameController* uniqueInstance;
public:
    static GameController* getInstance();

    void launch();

    void exit();

    void start();

    void pause();

    void end();
};
#endif
