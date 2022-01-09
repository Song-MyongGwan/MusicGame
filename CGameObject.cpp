#include "DXUT.h"
#include "Header.h"

void CGameObject::Update(float deltaTime)
{
	D3DXVECTOR2 tempPos = camera == NULL || !isUseCamera ? D3DXVECTOR2(0, 0) : camera->position;
	CMatrix::Update(deltaTime , tempPos);
}

void CGameObject::Render(LPD3DXSPRITE sprite)
{
}

void CGameObject::OnCollision(CGameObject* t_obj)
{
}

void CGameObject::SetCollider(float left, float right, float top, float bottom)
{
	isCollision = true;

	SetRect(&rect, position.x - left * fabs(scale.x), position.y - top * fabs(scale.y),
				   position.x + right * fabs(scale.x), position.y + bottom * fabs(scale.y));
}
