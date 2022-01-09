#pragma once
class ObjectManager
{
public:
	CCamera* objectCamera;

	list<CGameObject*> updateList;

	static bool Compare(CGameObject* left, CGameObject* right)
	{
		return left->layer < right->layer;
	}

	void AddObject(CGameObject* obj)
	{
		updateList.push_back(obj);
		obj->camera = objectCamera;
	}

	void OnCollisionTest()
	{
		for each (CGameObject* obj_1 in updateList)
		{
			if (obj_1->isCollision == false) continue;
			for each (CGameObject * obj_2 in updateList)
			{
				if (obj_1 == obj_2) continue;
				if (obj_2->isCollision == false) continue;

				RECT ref;
				if (IntersectRect(&ref, &obj_1->rect, &obj_2->rect))
				{
					obj_1->OnCollision(obj_2);
				}
			}
		}
	}

	void UpdateAll(float deltaTime)
	{
		list<CGameObject*> removeList;
		for each (CGameObject* obj in updateList)
		{
			obj->Update(deltaTime);

			if (obj->isRemoved)
				removeList.push_back(obj);
		}

		for each (CGameObject * obj in removeList)
		{
			updateList.remove(obj);
			delete obj;
		}
		removeList.clear();
	}

	void RenderAll(LPD3DXSPRITE sprite)
	{
		updateList.sort(Compare);

		for each (CGameObject * obj in updateList)
		{
			obj->Render(sprite);
		}
	}

	void RemoveAll()
	{
		for each (CGameObject * obj in updateList)
			delete obj;

		updateList.clear();
	}
};