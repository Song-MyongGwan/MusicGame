#pragma once
class CScene
{
public:
	ObjectManager objectManager;
	CCamera* mainCamera;

	bool doChangeScene = false;
	SceneName changeSceneName;

	static CScene* currentScene;
public:
	virtual ~CScene(){};
	virtual void Update(float deltaTime) = 0;
	virtual void Render(LPD3DXSPRITE sprite) = 0;
	virtual void FontRender() = 0;

	void LoadScene(SceneName sceneName);

};

extern CScene* ReturnScene();