#pragma once
#include <2d/CCAnimation.h>

namespace marcos
{
	class AnimationManager
	{
	public:

		AnimationManager();
		~AnimationManager();


		static void init();

		static cocos2d::Animation* setAnimation(const std::string a_String, const int a_NumFrames, const float a_Width, const float a_Height, const float a_Delay);

		static cocos2d::Animation * setAnimation(const std::string a_String, const int a_NumFrames, const int a_rows, const float a_Width, const float a_Height, const float a_Delay);

		//boss
		static cocos2d::Animation* m_BossFlameAnimation;
		//static cocos2d::Animation* m_BossFlameTellAnimation;

		static cocos2d::Animation* m_BossSpitAnimation;
		static cocos2d::Animation* m_BossSpitTellAnimation;



	private:


	};
}
