#include "DXUT.h"
#include "Header.h"

Note::Note(int NoteTag)
{
	pivot = { 59, 25 };
	tag = NOTE;
	switch (NoteTag)
	{
	case 1:
		position = { 465, -200 }; break;
	case 2:
		position = { 582, -200 }; break;
	case 3:
		position = { 699, -200 }; break;
	case 4:
		position = { 816, -200 }; break;
	}

}

Note::~Note()
{
}

void Note::Update(float deltaTime)
{
	position.y += NoteSpd * deltaTime;

	SetCollider(59, 59, 25, 25);

	CGameObject::Update(deltaTime);
}

void Note::Render(LPD3DXSPRITE sprite)
{
	Draw(sprite, SetTexture(L"Assets/UI/Note", 1));
}

void Note::OnCollision(CGameObject* t_obj)
{
}

void Note::bRemove(int ColliderTAG)
{
	isRemoved = true;
	this->ColliderTAG = ColliderTAG;
}
