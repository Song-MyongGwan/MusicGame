#include "DXUT.h"
#include "Header.h"

CTexture * CAssetManager::LoadTexture(LPCWSTR filename, int maxScene)
{
	if (textures[filename] == NULL)
	{
		textures[filename] = new CTexture(filename, maxScene);
	}
	else
	{
		return textures[filename];
	}
	return textures[filename];;
}

void CAssetManager::TermAssets()
{
	for each (auto texture in textures)
	{
		delete texture.second;
	}

	textures.clear();
}