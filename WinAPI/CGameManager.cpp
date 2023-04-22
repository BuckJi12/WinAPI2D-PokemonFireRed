#include "framework.h"
#include "CGameManager.h"

CGameManager::CGameManager()
{
	debugMode = false;
	canMeet = true;
	randomValue = 0;
	srand(time(NULL));
}

CGameManager::~CGameManager()
{
}

void CGameManager::ChangeDebugMode()
{
	debugMode = !debugMode;
}

void CGameManager::SetRandomValue()
{
	canMeet = true;
	randomValue = rand() % 15 + 5;
	Logger::Debug(randomValue + L"");
}

void CGameManager::Init()
{
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
