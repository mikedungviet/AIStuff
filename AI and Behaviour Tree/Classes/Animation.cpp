#include "Animation.h"
#include <2d/CCAnimationCache.h>

//static variable initialization

//boss

cocos2d::Animation* marcos::AnimationManager::m_BossFlameAnimation = new cocos2d::Animation();
cocos2d::Animation* marcos::AnimationManager::m_BossFlameTellAnimation = new cocos2d::Animation();

cocos2d::Animation* marcos::AnimationManager::m_BossSpitAnimation = new cocos2d::Animation();
cocos2d::Animation* marcos::AnimationManager::m_BossSpitTellAnimation = new cocos2d::Animation();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																			  //
//															Animation Class																	  //
//																																			  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

marcos::AnimationManager::AnimationManager()
{

}

marcos::AnimationManager::~AnimationManager()
{

}

void marcos::AnimationManager::init()
{	
	//////////////////////////////////////////// B O S S ///////////////////////////////////////////

	m_BossFlameTellAnimation = setAnimation("Sprites/boss_flamethrow.png", 27, 500, 1300, 0.1f);
	cocos2d::AnimationCache::getInstance()->addAnimation(m_BossFlameTellAnimation, "boss_flame_tell_animation_key");

	m_BossFlameAnimation = setAnimation("Sprites/flame.png", 8, 3, 1920, 500, 0.1f);
	cocos2d::AnimationCache::getInstance()->addAnimation(m_BossFlameAnimation, "boss_flame_animation_key");

	m_BossSpitAnimation = setAnimation("Sprites/fire_ball.png", 12, 70, 70, 0.1f);
	cocos2d::AnimationCache::getInstance()->addAnimation(m_BossSpitAnimation, "boss_spit_animation_key");

	m_BossSpitTellAnimation = setAnimation("Sprites/boss_projectile_attack.png", 23, 500, 1300, 0.1f);
	cocos2d::AnimationCache::getInstance()->addAnimation(m_BossSpitTellAnimation, "boss_spit_tell_animation_key");

}

//Animation setter, to store the animation frames in the animation cache to be called later
cocos2d::Animation* marcos::AnimationManager::setAnimation(const std::string a_String, const int a_NumFrames, const float a_Width, const float a_Height, const float a_Delay)
{
	cocos2d::Vector<cocos2d::SpriteFrame*> m_AnimFrames;

	for (int i = 0; i < a_NumFrames; i++)
	{
		auto frame = cocos2d::SpriteFrame::create(a_String, cocos2d::Rect(a_Width * i, 3, a_Width, a_Height));
		m_AnimFrames.pushBack(frame);
	}

	auto Animation = cocos2d::Animation::createWithSpriteFrames(m_AnimFrames, a_Delay);
	return Animation;

}

cocos2d::Animation* marcos::AnimationManager::setAnimation(const std::string a_String, const int a_RowFrames, const int a_rows, const float a_Width, const float a_Height, const float a_Delay)
{
	cocos2d::Vector<cocos2d::SpriteFrame*> m_AnimFrames;

	for (int i = 0; i < a_rows; i++)
	{
		for (int j = 0; j < a_RowFrames || j < 8; j++)
		{
			auto frame = cocos2d::SpriteFrame::create(a_String, cocos2d::Rect(a_Width * j, a_Height * i, a_Width, a_Height));
			m_AnimFrames.pushBack(frame);
		}
	}

	auto Animation = cocos2d::Animation::createWithSpriteFrames(m_AnimFrames, a_Delay);
	return Animation;

}