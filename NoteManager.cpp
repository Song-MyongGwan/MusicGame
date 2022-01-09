#include "DXUT.h"
#include "Header.h"

NoteManager::NoteManager()
{
	NoteCreateTime = 0.1;
	NoteCreateTimer = 0.0f;

	noteCount = 0;

	note = nullptr;

	takeDamage = false;

	comboHeal = false;
	comboCount = 0;
	number1 = 0;
	number10 = 0;
}

NoteManager::~NoteManager()
{
}

void NoteManager::Update(float deltaTime)
{
	comboHeal = false;

	if (NoteCreateTimer > NoteCreateTime)
	{
		NoteCreateTimer = 0;
		if (noteData[noteCount] != 0)
		{
			ReturnScene()->objectManager.AddObject(note = new Note(noteData[noteCount]));
			noteList.push_back(note);
		}
		noteCount++;
	}

	for (auto it = noteList.begin(); it != noteList.end(); it++)
	{
		if ((*it)->isRemoved == true)
			removeList.push_back((*it));

		if ((*it)->position.y > 540)
		{
			takeDamage = true;
			(*it)->MissFont = true;
			(*it)->isRemoved = true;
			removeList.push_back((*it));
		}
	}

	for (auto it = removeList.begin(); it != removeList.end(); it++)
	{
		if ((*it)->MissFont == true)
		{
			comboCount = 0;
			number1 = 0;
			number10 = 0;
			ReturnScene()->mainCamera->CameraShake(5, 0.1f);
			ReturnScene()->objectManager.AddObject(new ScoreFont(4));
		}
		else
		{
			comboHeal = true;
			comboCount++;

			switch ((*it)->ColliderTAG)
			{
			case 1:
				ReturnScene()->objectManager.AddObject(new ScoreFont(1)); break;
			case 2:
				ReturnScene()->objectManager.AddObject(new ScoreFont(2)); break;
			case 3:
				ReturnScene()->objectManager.AddObject(new ScoreFont(3)); break;
			}

			ReturnScene()->objectManager.AddObject(new Effect((*it)->position));

			if (comboCount > 9)
			{
				comboCount = 0;
				number10++;
			}

			number1 = comboCount;

			ReturnScene()->objectManager.AddObject(new comboFont(Vector2(620, 380), number10));
			ReturnScene()->objectManager.AddObject(new comboFont(Vector2(650, 380), number1));
		}
		

		noteList.remove((*it));
	}

	removeList.clear();

	NoteCreateTimer += deltaTime;

	CGameObject::Update(deltaTime);
}

void NoteManager::Render(LPD3DXSPRITE sprite)
{
}

void NoteManager::OnCollision(CGameObject* t_obj)
{
}

bool NoteManager::MissNote()
{
	return takeDamage;
}
