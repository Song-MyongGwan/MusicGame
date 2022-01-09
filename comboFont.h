#pragma once
class comboFont : public CGameObject
{
public:
	TCHAR tempName[100];
	WCHAR* filename;

	float visibleTime;
	float visibleTimer;

	comboFont(Vector2 pos, int value);
	~comboFont();

	// CGameObject을(를) 통해 상속됨
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;
};

