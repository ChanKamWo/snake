#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "GameController.h"
#include "base\CCDirector.h"
#include "IntroScene.h"

USING_NS_CC;

GameController* GameController::getInstance(){
    if ( !uniqueInstance )
    {
        uniqueInstance = new GameController();
    }
    return uniqueInstance;
}

void GameController::launch()
{
    Scene* introscene = IntroScene::createScene();
    auto director = Director::getInstance();

}

void GameController::exit()
{
}

void GameController::start()
{
}

void GameController::pause()
{
}

void GameController::end()
{
}
