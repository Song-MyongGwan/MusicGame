#pragma once

#include "DXUT.h"

typedef D3DXVECTOR3 Vector3;
typedef D3DXVECTOR2 Vector2;

#define SetTexture(filename, maxScene) CAssetManager::GetInstance()->LoadTexture(filename, maxScene)
#define Input KeyManager::GetInstance()
