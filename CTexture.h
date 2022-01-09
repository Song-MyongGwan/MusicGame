#pragma once
class CTexture
{
public:
	LPDIRECT3DTEXTURE9* textures;
	int width, height;
	int maxScene;

	LPDIRECT3DTEXTURE9 GetTexture(int idx)
	{
		if (idx < 0 || idx > maxScene)
			return NULL;

		return textures[idx];
	}
public:
	CTexture(LPCWSTR filename, int maxScene);
	~CTexture();
};

