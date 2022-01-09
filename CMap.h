#pragma once
class CMap : public CGameObject
{
public:
	bool colorPlus;
	bool alphaPlus;

	int colorCount;
	int minColorCount;
	int maxColorCount;
	int alphaCount;

	float colorTime;
	float colorTimer;

	CMatrix introMan;
	CMatrix introFont;

	CMap();
	~CMap();
	// CGameObject을(를) 통해 상속됨
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;
};

