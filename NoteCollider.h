#pragma once

class NoteCollider : public CGameObject
{
public:
	PlayerBox* pBox;

	int ColliderTAG;

	NoteCollider(PlayerBox* pBox);
	~NoteCollider();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;
};

