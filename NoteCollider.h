#pragma once

class NoteCollider : public CGameObject
{
public:
	PlayerBox* pBox;

	int ColliderTAG;

	NoteCollider(PlayerBox* pBox);
	~NoteCollider();

	// CGameObject을(를) 통해 상속됨
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;
};

