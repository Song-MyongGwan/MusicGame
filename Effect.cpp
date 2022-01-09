#include "DXUT.h"
#include "Header.h"

Effect::Effect(Vector2 pos)
{
	position = pos;
	pivot = { 512, 512 };
	scale = { 0.1, 0.1 };
	
	layer = 1;

	visibleTimer = 0.0f;
	visibleTime = 0.5f;
}

Effect::~Effect()
{
}

void Effect::Update(float deltaTime)
{
	if (visibleTimer > visibleTime)
	{
		isRemoved = true;
	}

	visibleTimer += deltaTime;

	CGameObject::Update(deltaTime);
}

void Effect::Render(LPD3DXSPRITE sprite)
{
	Draw(sprite, SetTexture(L"Assets/Effect/Glow", 1));
}

void Effect::OnCollision(CGameObject* t_obj)
{
}
