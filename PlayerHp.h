#pragma once

class PlayerHp : public CGameObject
{
public:
	CMatrix hpFrame;
	NoteManager* noteManager;
	float hp;
	float maxHp;


	PlayerHp(NoteManager* noteManager);
	~PlayerHp();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;

};

