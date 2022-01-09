#pragma once

class ButtonEft : public CGameObject
{
public:
	WCHAR* filename;
	PlayerBox* pBox;

	ButtonEft(PlayerBox* pBox);
	~ButtonEft();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Update(float deltaTime) override;

	virtual void Render(LPD3DXSPRITE sprite) override;

	virtual void OnCollision(CGameObject* t_obj) override;

};
