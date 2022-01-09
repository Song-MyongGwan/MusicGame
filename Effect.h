#pragma once

class Effect : public CGameObject
{
public:
	float visibleTimer;
	float visibleTime;

	Effect(Vector2 pos);
	~Effect();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;

};

