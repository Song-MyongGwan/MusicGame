#include "DXUT.h"
#include "Header.h"

ScoreFont::ScoreFont(int FontTAG)
{
	pivot = { 150, 75 };
	scale = { 0.7, 0.7 };
	position = { 650, 450 };

	this->FontTAG = FontTAG;

	visibleTime = 0.2f;
	visibleTimer = 0.0f;

	switch (FontTAG)
	{
	case 1:
		filename = L"Assets/UI/Font/PerfectFont"; break;
	case 2:
		filename = L"Assets/UI/Font/GreatFont"; break;
	case 3:
		filename = L"Assets/UI/Font/GoodFont"; break;
	case 4:
		filename = L"Assets/UI/Font/MissFont"; break;
	}
}

ScoreFont::~ScoreFont()
{
}

void ScoreFont::Update(float deltaTime)
{
	if (visibleTimer > visibleTime)
	{
		visibleTimer = 0;
		isRemoved = true;
	}

	visibleTimer += deltaTime;

	CGameObject::Update(deltaTime);
}

void ScoreFont::Render(LPD3DXSPRITE sprite)
{
	Draw(sprite, SetTexture(filename, 1));
}

void ScoreFont::OnCollision(CGameObject* t_obj)
{
}
