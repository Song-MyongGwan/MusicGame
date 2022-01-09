#include "DXUT.h"
#include "Header.h"

NoteCollider::NoteCollider(PlayerBox* pBox)
{
	ColliderTAG = 0;

	this->pBox = pBox;

	position = { pBox->position.x, 530 };
}

NoteCollider::~NoteCollider()
{


}

void NoteCollider::Update(float deltaTime)
{
	SetCollider(1, 1, 200, 200);

	CGameObject::Update(deltaTime);
}

void NoteCollider::Render(LPD3DXSPRITE sprite)
{
	Draw(sprite, SetTexture(L"Assets/UI/pixel", 1));
}

void NoteCollider::OnCollision(CGameObject* t_obj)
{
	if (pBox->bInput)
	{
		if (t_obj->tag == NOTE)
		{
			float hitY = abs(t_obj->position.y - position.y);

			if (hitY < 10)
				static_cast<Note*>(t_obj)->bRemove(1);
			else if (hitY < 20)
				static_cast<Note*>(t_obj)->bRemove(2);
			else if (hitY < 40)
				static_cast<Note*>(t_obj)->bRemove(3);
		}
	}
}

