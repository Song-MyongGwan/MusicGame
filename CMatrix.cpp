#include "DXUT.h"
#include "Header.h"

CMatrix::CMatrix()
{
	D3DXMatrixIdentity(&matrix);
}

void CMatrix::Update(float deltaTime, D3DXVECTOR2 cameraPos)
{
	D3DXVECTOR2 pos = position - pivot - cameraPos;

	D3DXMatrixTransformation2D(&matrix, &pivot, 0, &scale, &pivot, D3DXToRadian(rotation), &pos);

	if (animation && isAniEnd == false)
	{
		isAniPlaying = true;
		aniTimer += deltaTime;
		if (aniTimer >= aniTime)
		{
			aniTimer = 0;
			if (++currentScene >= endScene)
			{
				if (isAniRepeat)
				{
					currentScene = startScene;
				}
				else
				{
					currentScene = endScene;
					isAniEnd = true;
					isAniPlaying = false;
				}
			}
		}
	}
}

void CMatrix::Draw(LPD3DXSPRITE sprite, CTexture* texture, RECT* drawRect)
{
	sprite->SetTransform(&matrix);

	sprite->Draw(texture->GetTexture(currentScene),
		drawRect, NULL , NULL,
		D3DCOLOR_ARGB(a, r, g, b));
}

void CMatrix::SetAnimation(float rate, int startScene, int endScene, bool repeat)
{
	animation = true;
	aniTimer = 0;
	aniTime = rate;
	this->currentScene = startScene;
	this->startScene = startScene;
	this->endScene = endScene;
	isAniRepeat = repeat;
	isAniPlaying = false;
	isAniEnd = false;
}

void CMatrix::SetColor(int r, int g, int b, int a)
{
	this->a = a;
	this->r = r;
	this->g = g;
	this->b = b;
}
