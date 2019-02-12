#pragma once

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    bool init() override;
    
    // a selector callback
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};
