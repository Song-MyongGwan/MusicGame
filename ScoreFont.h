#pragma once

class ScoreFont : public CGameObject
{
public:
	int FontTAG;

	float visibleTime;
	float visibleTimer;

	WCHAR* filename;

	ScoreFont(int FontTAG);
	~ScoreFont();
	// CGameObject을(를) 통해 상속됨
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;
};

