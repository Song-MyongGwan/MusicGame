#pragma once
class CGameObject : public CMatrix
{
public:
	CCamera* camera;

	int tag = NONE;

	bool isCollision = false;
	bool isRemoved = false;
	bool isUseCamera = true;

	RECT rect;
	int layer = 0;

public:
	virtual void Update(float deltaTime) = 0;
	virtual void Render(LPD3DXSPRITE sprite) = 0;
	virtual void OnCollision(CGameObject* t_obj) = 0;

	void SetCollider(float left, float right, float top, float bottom);
};

