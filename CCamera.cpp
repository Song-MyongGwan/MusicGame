#include "DXUT.h"
#include "Header.h"

void CCamera::Update(float deltaTime)
{
	if (isShake)
	{
		if (shakeTimer < shakeTime)
		{
			shakeTimer += deltaTime;
			position += D3DXVECTOR2((rand() % 3 - 1) * shakePower, (rand() % 3 - 1) * shakePower);
		}
		else
			isShake = false;
	}

	if (target)
	{
		D3DXVec2Lerp(&position, &position, &(target->position - pivot), 0.1f);
		originPosition = position;
	}
	else
	{
		D3DXVec2Lerp(&position, &position, &originPosition, 0.1f);
	}
}

void CCamera::CameraShake(float power, float rate)
{
	isShake = true;

	shakeTimer = 0;
	shakeTime = rate;

	shakePower = power;
}
