#include "DXUT.h"
#include "Header.h"

CTexture::CTexture(LPCWSTR filename, int maxScene)
{
	textures = new LPDIRECT3DTEXTURE9[maxScene];
	this->maxScene = maxScene;

	D3DXIMAGE_INFO imageInfo;
	for (int i = 0; i < maxScene; i++)
	{
		wchar_t temp[256];
		wsprintf(temp, L"%s%d.png", filename, i);

		D3DXGetImageInfoFromFile(temp, &imageInfo);

		if (FAILED(D3DXCreateTextureFromFileExW(
			DXUTGetD3D9Device(),
			temp,
			imageInfo.Width,
			imageInfo.Height,
			1,
			0,
			D3DFMT_A8R8G8B8,
			D3DPOOL_MANAGED,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			NULL,
			NULL,
			&textures[i]
		)))
		{
			MessageBox(DXUTGetHWND(),
				temp,
				L"이미지를 불러오지 못했습니다.",
				MB_OK);
		}
	}
	width = imageInfo.Width;
	height = imageInfo.Height;
}

CTexture::~CTexture()
{
	for (int i = 0; i < maxScene; i++)
		if (textures[i])
			textures[i]->Release();

	delete[] textures;
}
