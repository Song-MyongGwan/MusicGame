#include "DXUT.h"
#include "Header.h"

ButtonEft::ButtonEft(PlayerBox* pBox)
{
	pivot = { 59, 500 };
	position = { 0, 530 };
	position.x = pBox->position.x;

	this->pBox = pBox;

	filename = nullptr;
}

ButtonEft::~ButtonEft()
{
}

void ButtonEft::Update(float deltaTime)
{
	filename = nullptr;

	if (pBox->bInput)
	{
		filename = L"Assets/UI/buttonEft";
	}

	CGameObject::Update(deltaTime);
}

void ButtonEft::Render(LPD3DXSPRITE sprite)
{
	if (filename != nullptr)
	Draw(sprite, SetTexture(filename, 1));
}

void ButtonEft::OnCollision(CGameObject* t_obj)
{
}
