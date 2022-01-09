#pragma once
enum Tag
{
	NONE,
	NOTE,
};

enum SceneName
{
	TITLE,
	GAME,
};

#include <list>
#include <map>
using std::list;
using std::map;

#include "Macro.h"
#include "ScreenSize.h"

#include "SingleInstance.h"

#include "KeyManager.h"
#include "FontManager.h"

#include "CTexture.h"
#include "CAssetManager.h"

#include "CMatrix.h"
#include "CCamera.h"

#include "CGameObject.h"
#include "CMap.h"
#include "GameMap.h"

#include "ScoreFont.h"
#include "comboFont.h"

#include "PlayerBox.h"
#include "NoteCollider.h"
#include "ButtonEft.h"

#include "Effect.h"
#include "Note.h"

#include "NoteManager.h"

#include "PlayerHp.h"

#include "ObjectManager.h"

#include "CScene.h"
#include "CTitleScene.h"
#include "CGameScene.h"

#include "CGame.h"