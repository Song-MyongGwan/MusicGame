#include "DXUT.h"
#include "Header.h"

CMap::CMap()
{
	position = { 0, 0 };
	
	SetColor(255, 100, 100, 100);
	colorCount = 87;
	minColorCount = 87;
	maxColorCount = 177; // 127 +- 50;
	alphaPlus = true;
	alphaCount = 40;

	colorTime = 0.05f;

	colorTimer = 0.0f;

	colorPlus = true;

	layer = -10;
}

CMap::~CMap()
{
}

void CMap::Update(float deltaTime)
{
	SetColor(colorCount, colorCount, 0);
	introMan.SetColor(0, 255, -colorCount, alphaCount);

	if (colorTimer > colorTime)
	{
		colorTimer = 0;
		if (colorPlus)
			colorCount++;
		else
			colorCount--;

		if (alphaPlus)
			alphaCount += 2;
		else
			alphaCount -= 2;

		if (alphaCount > 220)
			alphaPlus = false;
		if (alphaCount < 40)
			alphaPlus = true;

		if (colorCount > maxColorCount)
			colorPlus = false;
		if (colorCount < minColorCount)
			colorPlus = true;
	}

	colorTimer += deltaTime;

	introFont.Update(deltaTime);
	introMan.Update(deltaTime, ReturnScene()->mainCamera->position);
	CGameObject::Update(deltaTime);
}

void CMap::Render(LPD3DXSPRITE sprite)
{
	Draw(sprite, SetTexture(L"Assets/Map/introMap", 1));
	introFont.Draw(sprite, SetTexture(L"Assets/Map/introFont", 1));
	introMan.Draw(sprite, SetTexture(L"Assets/Map/introMan", 1));
}

void CMap::OnCollision(CGameObject* t_obj)
{
}
