#include "framework.h"
#include "CGameManager.h"

CGameManager::CGameManager()
{
	m_meetTime = 0;
	m_debugMode = false;
	m_canMeet = true;
	m_randomValue = 0;
	srand(time(NULL));
}

CGameManager::~CGameManager()
{
}

void CGameManager::ChangeDebugMode()
{
	m_debugMode = !m_debugMode;
}

void CGameManager::SetRandomValue()
{
	GAME->m_meetTime = 0;
	m_canMeet = true;
	m_randomValue = rand() % 15 + 5;
}

void CGameManager::Init()
{
	SetRandomValue();
}

void CGameManager::Update()
{
	if (BUTTONDOWN(VK_F5))
	{
		ChangeDebugMode();
	}

	if (BUTTONDOWN(VK_F6))
	{
		SetRandomValue();
	}
}

void CGameManager::Release()
{
}
