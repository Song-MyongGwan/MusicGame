#include "DXUT.h"
#include "Header.h"
#include <ctime>

CGameScene::CGameScene()
{
	srand(time(NULL));

	CScene::currentScene = this;

	mainCamera = new CCamera();
	objectManager.objectCamera = mainCamera;
	objectManager.AddObject(gameMap = new GameMap());
	objectManager.AddObject(noteManager = new NoteManager());
	objectManager.AddObject(new PlayerHp(noteManager));

	objectManager.AddObject(new PlayerBox('D', Vector2(465, 639)));
	objectManager.AddObject(new PlayerBox('F', Vector2(582, 619)));
	objectManager.AddObject(new PlayerBox('J', Vector2(699, 619)));
	objectManager.AddObject(new PlayerBox('K', Vector2(816, 639)));
}

CGameScene::~CGameScene()
{
	delete mainCamera;

	objectManager.RemoveAll();
}

void CGameScene::Update(float deltaTime)
{
	if (Input->GetKey('R'))
		LoadScene(GAME);

	mainCamera->Update(deltaTime);

	objectManager.UpdateAll(deltaTime);
	objectManager.OnCollisionTest();
}

void CGameScene::Render(LPD3DXSPRITE sprite)
{
	objectManager.RenderAll(sprite);
}

void CGameScene::FontRender()
{
}
