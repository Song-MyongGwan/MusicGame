#pragma once

class PlayerBox : public CGameObject
{
public:
	bool bInput;

	char inputKey;

	WCHAR* filename;

	PlayerBox(char inputKey, Vector2 pos);
	~PlayerBox();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Update(float deltaTime) override;

	virtual void Render(LPD3DXSPRITE sprite) override;

	virtual void OnCollision(CGameObject* t_obj) override;

};

