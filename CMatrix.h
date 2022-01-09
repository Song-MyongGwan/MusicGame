#pragma once
class CMatrix
{
public:
	D3DXMATRIX matrix;
	D3DXVECTOR2 position = { 0,0 };
	D3DXVECTOR2 scale = { 1,1 };
	D3DXVECTOR2 pivot = { 0,0 };

	float rotation = 0;

	int a = 255, r = 255, g = 255, b = 255;

	bool animation = false;

	float aniTimer = 0, aniTime = 0;
	int currentScene = 0, startScene = 0, endScene = 0;
	bool isAniPlaying = false, isAniEnd = false, isAniRepeat = false;

public:
	CMatrix();
	virtual void Update(float deltaTime, D3DXVECTOR2 cameraPos = { 0,0 });
	void Draw(LPD3DXSPRITE sprite, CTexture* texture, RECT* drawRect = NULL);
	void SetAnimation(float rate, int startScene, int endScene, bool repeat = false);
	void SetColor(int r, int g, int b, int a = 255);
};

