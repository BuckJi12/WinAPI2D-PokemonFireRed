#include "framework.h"
#include "CScenePalletTown.h"

#include "CPlayer.h"
#include "CImageObject.h"
#include "CWarp.h"

CScenePalletTown::CScenePalletTown()
{
	m_pPlayer = nullptr;
	m_pImageBackGround = nullptr;
	m_pWarp = nullptr;
	m_pWarp2 = nullptr;
	m_pWarp3 = nullptr;
}

CScenePalletTown::~CScenePalletTown()
{
	delete m_pPlayer;
	delete m_pImageBackGround;
	delete m_pWarp;
	delete m_pWarp2;
	delete m_pWarp3;
}

void CScenePalletTown::Init()
{
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"PalletTown", L"Image\\Map\\PalletTown.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetPos(440, 560);
	m_pPlayer->ChangeDir(PlayerDir::Left);
	AddGameObject(m_pPlayer);

	// 플레이어 집
	m_pWarp = new CWarp;
	m_pWarp->SetPos(410, 475);
	m_pWarp->SetScale(100, 30);
	m_pWarp->SetDestination(GroupScene::PlayerHome1F);
	AddGameObject(m_pWarp);

	// 오박사 연구소
	m_pWarp2 = new CWarp;
	m_pWarp2->SetPos(1060, 850);
	m_pWarp2->SetScale(100, 30);
	m_pWarp2->SetDestination(GroupScene::OakLab);
	AddGameObject(m_pWarp2);

	// 1번 도로
	m_pWarp3 = new CWarp;
	m_pWarp3->SetPos(830, 20);
	m_pWarp3->SetScale(120, 30);
	m_pWarp3->SetDestination(GroupScene::PlayerHome1F);
	AddGameObject(m_pWarp3);

	LoadTile(GETPATH + L"Tile\\PalletTown.tile");
}

void CScenePalletTown::Enter()
{
	CAMERA->FadeIn(1.0f);
	CAMERA->SetTargetObj(m_pPlayer);
}

void CScenePalletTown::Update()
{
}

void CScenePalletTown::Render()
{
}

void CScenePalletTown::Exit()
{
}

void CScenePalletTown::Release()
{
}
