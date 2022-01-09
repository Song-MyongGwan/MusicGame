#pragma once

class Note : public CGameObject
{
public:
	bool MissFont = false;

	int NoteSpd = 300;
	int ColliderTAG = 0;

	Note(int NoteTag);
	~Note();
	// CGameObject��(��) ���� ��ӵ�
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;
	void bRemove(int ColliderTAG);
};

