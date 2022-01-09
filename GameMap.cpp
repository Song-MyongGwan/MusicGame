#include "DXUT.h"
#include "Header.h"

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}

void GameMap::Update(float deltaTime)
{
	CGameObject::Update(deltaTime);
}

void GameMap::Render(LPD3DXSPRITE sprite)
{
	Draw(sprite, SetTexture(L"Assets/Map/GameMap", 1));
}

void GameMap::OnCollision(CGameObject* t_obj)
{
}
