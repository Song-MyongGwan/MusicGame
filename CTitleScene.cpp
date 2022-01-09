#include "DXUT.h"
#include "Header.h"

CTitleScene::CTitleScene()
{
	CScene::currentScene = this;

	mainCamera = new CCamera();
	objectManager.objectCamera = mainCamera;

	objectManager.AddObject(map = new CMap());
}

CTitleScene::~CTitleScene()
{
	objectManager.RemoveAll();
}

void CTitleScene::Update(float deltaTime)
{
	if (Input->GetKey(VK_SPACE) == 1)
	{
		LoadScene(GAME);
	}

	mainCamera->Update(deltaTime);

	objectManager.UpdateAll(deltaTime);
	objectManager.OnCollisionTest();
}

void CTitleScene::Render(LPD3DXSPRITE sprite)
{
	objectManager.RenderAll(sprite);
}

void CTitleScene::FontRender()
{
}
