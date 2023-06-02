#include "framework.h"
#include "CSceneMountain.h"

#include "CPlayer.h"
#include "CWarp.h"
#include "CNPCMewtwo.h"

CSceneMountain::CSceneMountain()
{
	m_pImageBackGround	= nullptr;
	m_pPlayer			= nullptr;
	m_pWarpToViridian	= nullptr;
	m_pNPCMewTwo		= nullptr;
}

CSceneMountain::~CSceneMountain()
{
}

void CSceneMountain::Init()
{
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"MountainBackGround", L"Image\\Map\\Mountain.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetPos(580, 726);
	m_pPlayer->ChangeDir(PlayerDir::Down);
	AddGameObject(m_pPlayer);

	m_pWarpToViridian = new CWarp;
	m_pWarpToViridian->SetDestination(GroupScene::ViridianTown);
	m_pWarpToViridian->SetPos(672, 730);
	m_pWarpToViridian->SetScale(60, 60);
	AddGameObject(m_pWarpToViridian);

	auto fightMewtwo = [](DWORD_PTR param)
	{
		GAME->SetCanMove(false);
		BATTLE->BattleInit(20, 75);
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Battle, 0.5f);
	};

	m_pNPCMewTwo = new CNPCMewtwo;
	m_pNPCMewTwo->SetCallBack(fightMewtwo, (DWORD_PTR)this);
	m_pNPCMewTwo->SetPos(606, 283);
	AddGameObject(m_pNPCMewTwo);


	LoadTile(GETPATH + L"Tile\\Mountain.tile");
}

void CSceneMountain::Enter()
{
	CAMERA->FadeIn(0.5f);
	CAMERA->SetTargetObj(m_pPlayer);
	SOUND->Play(SOUND->GetBGM(GroupScene::Mountain), 0.5f, true);
}

void CSceneMountain::Update()
{
}

void CSceneMountain::Render()
{
}

void CSceneMountain::Exit()
{
	SOUND->Pause(SOUND->GetBGM(GroupScene::Mountain));
}

void CSceneMountain::Release()
{
}
