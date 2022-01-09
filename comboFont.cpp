#include "DXUT.h"
#include "Header.h"

comboFont::comboFont(Vector2 pos, int value)
{
	position = pos;

	visibleTime = 0.2f;
	visibleTimer = 0.0f;

	pivot = { 35, 35 };

	//wsprintf(tempName, L"Assets/UI/Font/Number%d_", value);

	switch (value)
	{
	case 0:
		filename = L"Assets/UI/Font/Number0_"; break;
	case 1:
		filename = L"Assets/UI/Font/Number1_"; break;
	case 2:
		filename = L"Assets/UI/Font/Number2_"; break;
	case 3:
		filename = L"Assets/UI/Font/Number3_"; break;
	case 4:
		filename = L"Assets/UI/Font/Number4_"; break;
	case 5:
		filename = L"Assets/UI/Font/Number5_"; break;
	case 6:
		filename = L"Assets/UI/Font/Number6_"; break;
	case 7:
		filename = L"Assets/UI/Font/Number7_"; break;
	case 8:
		filename = L"Assets/UI/Font/Number8_"; break;
	case 9:
		filename = L"Assets/UI/Font/Number9_"; break;
	}
}

comboFont::~comboFont()
{
}

void comboFont::Update(float deltaTime)
{
	if (visibleTimer > visibleTime)
	{
		visibleTimer = 0;
		isRemoved = true;
	}

	a--;
	visibleTimer += deltaTime;

	CGameObject::Update(deltaTime);
}

void comboFont::Render(LPD3DXSPRITE sprite)
{
	Draw(sprite, SetTexture(filename, 1));
}

void comboFont::OnCollision(CGameObject* t_obj)
{
}
