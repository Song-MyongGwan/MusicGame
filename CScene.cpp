#include "DXUT.h"
#include "Header.h"

CScene* CScene::currentScene;
void CScene::LoadScene(SceneName sceneName)
{
	doChangeScene = true;
	changeSceneName = sceneName;
}

CScene * ReturnScene()
{
	return CScene::currentScene;
}
