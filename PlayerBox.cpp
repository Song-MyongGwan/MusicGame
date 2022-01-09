#include "DXUT.h"
#include "Header.h"

PlayerBox::PlayerBox(char inputKey, Vector2 pos)
{
	pivot = { 50, 50 };

	position = pos;
	this->inputKey = inputKey;
	filename = L"Assets/UI/PlayerButton";

	ReturnScene()->objectManager.AddObject(new ButtonEft(this));
	ReturnScene()->objectManager.AddObject(new NoteCollider(this));
}

PlayerBox::~PlayerBox()
{
}

void PlayerBox::Update(float deltaTime)
{
	bInput = false;
	filename = L"Assets/UI/PlayerButton";

	if (Input->GetKey(inputKey) == 2)
	{
		bInput = true;
		filename = L"Assets/UI/PlayerButton1_";
	}

	CGameObject::Update(deltaTime);
}

void PlayerBox::Render(LPD3DXSPRITE sprite)
{
	Draw(sprite, SetTexture(filename, 1));
}

void PlayerBox::OnCollision(CGameObject* t_obj)
{
}
