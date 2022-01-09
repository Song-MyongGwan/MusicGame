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
	// CGameObject��(��) ���� ��ӵ�
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;
};

