#include "framework.h"
#include "CGameManager.h"

#include "CMonsterBall.h"
#include "CMasterBall.h"

CGameManager::CGameManager()
{
	m_meetTime			= 0;
	m_debugMode			= false;
	m_canMove			= true;
	m_canMeet			= true;
	m_playerGetStarting = false;
	m_randomValue		= 0;
	srand(time(NULL));
}

CGameManager::~CGameManager()
{
}

void CGameManager::ChangeDebugMode()
{
	m_debugMode = !m_debugMode;
}

bool CGameManager::GetDebugMode()
{
	return m_debugMode;
}

bool CGameManager::GetCanMove()
{
	return m_canMove;
}

bool CGameManager::GetCanMeet()
{
	return m_canMeet;
}

bool CGameManager::GetPlayerGetStarting()
{
	return m_playerGetStarting;
}

int CGameManager::GetValue()
{
	return m_randomValue;
}

void CGameManager::SetRandomValue()
{
	GAME->m_meetTime = 0;
	m_canMeet = true;
	m_randomValue = rand() % 15 + 5;
}

void CGameManager::SetPlayerGetStarting(bool get)
{
	m_playerGetStarting = get;
}

void CGameManager::SetCanMove(bool canMove)
{
	m_canMove = canMove;
}

void CGameManager::GetMonsterBall()
{
	PLAYER->AddItem(m_ball, 5);
}

void CGameManager::Init()
{
	SetRandomValue();
	m_ball = new CMonsterBall;
	m_ball->Init();
	PLAYER->AddItem(m_ball, 5);
	m_masterBall = new CMasterBall;
	m_masterBall->Init();
	PLAYER->AddItem(m_masterBall, 1);
}

void CGameManager::Update()
{
	if (BUTTONDOWN(VK_F5))
	{
		ChangeDebugMode();
	}

	if (BUTTONDOWN(VK_F6))
	{
		GetMonsterBall();
	}

	if (BUTTONDOWN('P'))
	{
		DELAYCHANGESCENE(GroupScene::PokemonList, 0.5f);
	}
}

void CGameManager::Release()
{
}
