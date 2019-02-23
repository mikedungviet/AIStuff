#pragma once

#include "cocos2d.h"
#include "Boss1Attack.h"

class HelloWorld : public cocos2d::Scene
{
private:
	FlameThrower *flame;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();  
	void update(float deltaTime) override;

    CREATE_FUNC(HelloWorld);
};