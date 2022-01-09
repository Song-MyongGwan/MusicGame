#pragma once

class GameMap : public CGameObject
{
public:
	GameMap();
	~GameMap();
	// CGameObject을(를) 통해 상속됨
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;
};

