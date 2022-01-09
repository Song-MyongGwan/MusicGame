#include "DXUT.h"
#include "Header.h"

CScene* gScene;
LPD3DXSPRITE gSprite;
void ChangeScene(SceneName sceneName)
{
	if (gScene)
		delete gScene;

	switch (sceneName)
	{
	case TITLE:
		gScene = new CTitleScene();
		break;
	case GAME:
		gScene = new CGameScene();
		break;
	}
}

void Init()
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &gSprite);

	ChangeScene(TITLE);
}

void Term()
{
	if (gScene)
		delete gScene;

	if (gSprite)
		gSprite->Release();

	CAssetManager::GetInstance()->TermAssets();
}

void Update(float deltaTime)
{
	if (gScene)
	{
		if (gScene->doChangeScene)
			ChangeScene(gScene->changeSceneName);

		gScene->Update(deltaTime);
	}
}

void Render()
{
	gSprite->Begin(D3DXSPRITE_ALPHABLEND);

	if (gScene) gScene->Render(gSprite);

	gSprite->End();

	if (gScene) gScene->FontRender();

}
