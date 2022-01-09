#pragma once
class KeyManager : public SingleInstance<KeyManager>
{
public:
	int keyState[256] = { 0 };
	D3DXVECTOR2 mousePos = { 0,0 };

	void SetMousePos(int x, int y)
	{
		mousePos.x = x;
		mousePos.y = y;
	}

	int GetKey(int key)
	{
		if (keyState[key] == 0)
		{
			if (GetKeyState(key) & 0x8000)
			{
				keyState[key] = 1;
				return 1;
			}
		}
		else if (keyState[key] == 1)
		{
			if (GetKeyState(key) & 0x8000)
			{
				return 2;
			}
			else
			{
				keyState[key] = 0;
				return 3;
			}
		}
		return 0;
	}
};