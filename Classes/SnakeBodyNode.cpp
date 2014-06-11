#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "SnakeBodyNode.h"

bool SnakeBodyNode::init(){

}

SnakeBodyNode* SnakeBodyNode::create( BodyNodeType type ){
    SnakeBodyNode *pRet = new SnakeBodyNode( type );
    if ( pRet && pRet->init() )
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }

