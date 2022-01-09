#pragma once
class CCamera
{
public:
	CMatrix* target = NULL;

	D3DXVECTOR2 position = { 0,0 };
	D3DXVECTOR2 pivot = { 960,540 };

	D3DXVECTOR2 originPosition = position;

	bool isShake = false;
	float shakeTimer = 0, shakeTime = 0;
	float shakePower = 0;

public:
	void Update(float deltaTime);

	void CameraShake(float power, float rate);
	void SetTarget(CMatrix* inputTarget) { target = inputTarget; }
};

