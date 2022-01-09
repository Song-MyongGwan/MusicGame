#include "DXUT.h"
#include "Header.h"

PlayerHp::PlayerHp(NoteManager* noteManger)
{
	rotation = 180;

	scale = { 0.5, 0.7 };
	hpFrame.scale = { 0.5, 0.7 };

	pivot = { 35, 300 };
	hpFrame.pivot = { 35, 300 };
	
	position = { 30, 350 };
	hpFrame.position = { 30, 350 };

	//----------------
	this->noteManager = noteManger;

	maxHp = 100;
	hp = maxHp;
	
	isUseCamera = false;
}

PlayerHp::~PlayerHp()
{
}

void PlayerHp::Update(float deltaTime)
{
	if (noteManager->comboHeal)
		if (hp < 100)
			hp++;

	if (noteManager->MissNote())
	{
		hp -= 10;
		noteManager->takeDamage = false;
	}

	hpFrame.Update(deltaTime);
	CGameObject::Update(deltaTime);
}

void PlayerHp::Render(LPD3DXSPRITE sprite)
{
	RECT hpRect = { 0, 0, 200, 600 * (hp / maxHp) };

	hpFrame.Draw(sprite, SetTexture(L"Assets/UI/hpFrame", 1));
	Draw(sprite, SetTexture(L"Assets/UI/hpBar", 1), &hpRect);
}

void PlayerHp::OnCollision(CGameObject* t_obj)
{
}
