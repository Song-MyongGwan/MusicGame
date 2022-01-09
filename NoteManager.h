#pragma once

class NoteManager : public CGameObject
{
public:
	std::list<Note*> noteList;
	std::list<Note*> removeList;
	Note* note;

	int noteData[100] = { 0, 0, 0, 0, 0, 0, 0, 3, 2, 1,  2,  3, 3,  3, 2, 2 , 2, 3, 4,  4, 3, 2,1, 2,  3, 3, 3,   2,   2, 3, 2, 1, 0};

	int noteCount;

	bool comboHeal;

	int noteTAG = 0;
	int takeDamage;

	int comboCount;
	int number1;
	int number10;

	float NoteCreateTime;
	float NoteCreateTimer;

	NoteManager();
	~NoteManager();

	// CGameObject을(를) 통해 상속됨
	virtual void Update(float deltaTime) override;
	virtual void Render(LPD3DXSPRITE sprite) override;
	virtual void OnCollision(CGameObject* t_obj) override;
	bool MissNote();
};

