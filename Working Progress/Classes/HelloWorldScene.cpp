#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    const auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
   
	flame = new FlameThrower;
	this->addChild(flame->getSprite());
	this->addChild(flame->getHitBox());


	this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float deltaTime)
{
	flame->update(deltaTime);
}
