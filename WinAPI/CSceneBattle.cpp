#include "framework.h"
#include "CSceneBattle.h"

#include "CImageObject.h"
#include "CGameObject.h"

// Enviorment
#include "CPlayerFloor.h"
#include "COpponentFloor.h"

// UI
#include "CPlayerStatUI.h"

// Player
#include "CPlayerThrowBall.h"

// Turn
#include "CTurnEnter.h"
#include "CTurnPlayerReady.h"
#include "CTurnChooseAction.h"
#include "CTurnChooseMove.h"
#include "CTurnBattle.h"
#include "CTurnChange.h"
#include "CTurnBag.h"
#include "CTurnCatch.h"
#include "CTurnContinue.h"
#include "CTurnResult.h"

CSceneBattle::CSceneBattle()
{
	m_curTurn				= nullptr;
	m_pImageBackGround		= nullptr;
	m_pCursor				= nullptr;
	m_pImagePlayerStatUI	= nullptr;
	m_pTextBox				= nullptr;
	m_curTurnSituation		= TurnSituation::Change;
}

CSceneBattle::~CSceneBattle()
{
}

void CSceneBattle::SetTurnSituation(TurnSituation situation)
{
	m_curTurnSituation = situation;
}

void CSceneBattle::AddObjectThisScene(CGameObject* object)
{
	AddGameObject(object);
}

void CSceneBattle::ChangeTurn(PlayerAction action)
{
	m_curTurn->Exit();
	m_curTurn = m_mapTurns[action];
	m_curTurn->Enter();
}

TurnSituation CSceneBattle::GetCurSituation()
{
	return m_curTurnSituation;
}

CImageObject* CSceneBattle::GetCursor()
{
	return m_pCursor;
}

CPlayerStatUI* CSceneBattle::GetPlayerUI()
{
	return m_pImagePlayerStatUI;
}

CTextBox* CSceneBattle::GetTextBox()
{
	return m_pTextBox;
}

void CSceneBattle::CheckAddedGameObject()
{
	for (int i = 0; i < PLAYER->GetPlayerPokemonList().size(); i++)
	{
		if (FindGameObject(PLAYER->GetPlayerPokemonList()[i]))
			continue;
		else
		{
			AddGameObject(PLAYER->GetPlayerPokemonList()[i]);
			PLAYER->GetPlayerPokemonList()[i]->SetPos(1000, 1000);
		}
			
	}
}

void CSceneBattle::Init()
{
	// ¹è°æ
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"BackGround", L"Image\\Battle\\BackGround.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_pCursor = new CImageObject;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor", L"Image\\Battle\\Cursor.png"));
	m_pCursor->SetLayer(Layer::Environment3);
	m_pCursor->SetPos(1000, 1000);
	AddGameObject(m_pCursor);

	// UI
	m_pTextBox = new CTextBox;
	m_pTextBox->SetPos(1000, 1000);
	m_pTextBox->SetLayer(Layer::Environment2);
	AddGameObject(m_pTextBox);

	m_pImagePlayerStatUI = new CPlayerStatUI;
	m_pImagePlayerStatUI->Init();
	m_pImagePlayerStatUI->SetPos(1000, 1000);

	// Effect
	CEffect* fire = new CEffectFire;
	fire->SetPos(1000, 1000);
	RESOURCE->AddEffect(PokemonType::Fire, fire);
	CEffect* normal = new CEffectNormal;
	normal->SetPos(1000, 1000);
	RESOURCE->AddEffect(PokemonType::Normal, normal);
	CEffect* water = new CEffectWater;
	water->SetPos(1000, 1000);
	RESOURCE->AddEffect(PokemonType::Water, water);
	CEffect* grass = new CEffectGrass;
	grass->SetPos(1000, 1000);
	RESOURCE->AddEffect(PokemonType::Grass, grass);
	CEffect* lightning = new CEffectLightning;
	lightning->SetPos(1000, 1000);
	RESOURCE->AddEffect(PokemonType::Electric, lightning);
	CEffect* ice = new CEffectIce;
	ice->SetPos(1000, 1000);
	RESOURCE->AddEffect(PokemonType::Ice, ice);
	CEffect* psychic = new CEffectPsyChic;
	psychic->SetPos(1000, 1000);
	RESOURCE->AddEffect(PokemonType::Psychic, psychic);


	AddGameObject(fire);
	AddGameObject(normal);
	AddGameObject(water);
	AddGameObject(grass);

	// ÅÏ
	m_mapTurns.insert(make_pair(PlayerAction::Enter, new CTurnEnter(this)));
	m_mapTurns.insert(make_pair(PlayerAction::PlayerReady, new CTurnPlayerReady(this)));
	m_mapTurns.insert(make_pair(PlayerAction::ChooseAction, new CTurnChooseAction(this)));
	m_mapTurns.insert(make_pair(PlayerAction::ChooseMove, new CTurnChooseMove(this)));
	m_mapTurns.insert(make_pair(PlayerAction::Battle, new CTurnBattle(this)));
	m_mapTurns.insert(make_pair(PlayerAction::Change, new CTurnChange(this)));
	m_mapTurns.insert(make_pair(PlayerAction::Bag, new CTurnBag(this)));
	m_mapTurns.insert(make_pair(PlayerAction::Catch, new CTurnCatch(this)));
	m_mapTurns.insert(make_pair(PlayerAction::Continue, new CTurnContinue(this)));
	m_mapTurns.insert(make_pair(PlayerAction::Result, new CTurnResult(this)));

	m_mapTurns[PlayerAction::Enter]->Init();
	m_mapTurns[PlayerAction::PlayerReady]->Init();
	m_mapTurns[PlayerAction::ChooseAction]->Init();
	m_mapTurns[PlayerAction::ChooseMove]->Init();
	m_mapTurns[PlayerAction::Battle]->Init();
	m_mapTurns[PlayerAction::Change]->Init();
	m_mapTurns[PlayerAction::Bag]->Init();
	m_mapTurns[PlayerAction::Catch]->Init();
	m_mapTurns[PlayerAction::Continue]->Init();
	m_mapTurns[PlayerAction::Result]->Init();
}

void CSceneBattle::Enter()
{
	CAMERA->FadeIn(3.0f);
	BATTLE->BattleInit();
	m_curTurn = m_mapTurns[PlayerAction::Enter];
	m_curTurn->Enter();
	CheckAddedGameObject();
}

void CSceneBattle::Update()
{
	m_curTurn->Update();
}

void CSceneBattle::Render()
{
}

void CSceneBattle::Exit()
{
}

void CSceneBattle::Release()
{
	for (pair<PlayerAction, CTurn*> turn : m_mapTurns)
	{
		turn.second->Release();
	}

	DELETEOBJECT(m_pImageBackGround);
	DELETEOBJECT(m_pCursor);
	DELETEOBJECT(m_pImagePlayerStatUI);
	DELETEOBJECT(m_pTextBox);
}
