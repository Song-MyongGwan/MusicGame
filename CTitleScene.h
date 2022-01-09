#pragma once
class CTitleScene : public CScene
{
public:
	CMap* map;
	int tempColor = 0;
public:
	CTitleScene();
	~CTitleScene();
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void FontRender() override;
};

