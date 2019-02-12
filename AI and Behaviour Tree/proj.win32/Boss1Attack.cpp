#include "Boss1Attack.h"

LavaBall::LavaBall()
{
	/*
	 * With init velocity, should be able to calculate the needed angle
	 */
	theta = calculateAngle();
}

void LavaBall::update(const float& deltaT)
{
	//Update normally

	//Velocity_x is constant

	//Velocity_y += acceleration * deltaT

	//Position update like normal Or position_y += gravity*(deltaT)^2
}

float LavaBall::calculateAngle()
{
	//Calculate the Displacement_y and Displacement_x

	/*
	 * a = gravity.y/2 * (displacement_x)^2
	 * b= displacement_x
	 * c = gravity.y/2 * (displacement_x)^2 - displacement_y
	 * 
	 * tan(theta) = quadratic formula (link: https://cdn.kastatic.org/googleusercontent/nI2riiPBcl9hZ22KKdYZGFmsVNhcKLiuwPly9l1tU5BMaqcOs9bfPKRyoGAFgK-PNpc-c7x_tNuskGdzawvy_Pza)
	 */

	return 0.f;
}
