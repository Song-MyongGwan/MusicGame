#pragma once
class CGameScene : public CScene
{
public:
	GameMap* gameMap;
	NoteManager* noteManager;
public:
	CGameScene();
	~CGameScene();
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void FontRender() override;
};

