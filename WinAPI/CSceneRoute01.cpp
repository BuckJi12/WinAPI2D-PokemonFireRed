#include "framework.h"
#include "CSceneRoute01.h"

#include "CPlayer.h"
#include "CImageObject.h"
#include "CWarp.h"

CSceneRoute01::CSceneRoute01()
{
	m_pPlayer = nullptr;
	m_pImageBackGround = nullptr;
	m_pWarp = nullptr;
	m_pWarp2 = nullptr;
}

CSceneRoute01::~CSceneRoute01()
{
	delete m_pPlayer;
	delete m_pImageBackGround;
	delete m_pWarp;
	delete m_pWarp2;
}

void CSceneRoute01::Init()
{
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"Route01", L"Image\\Map\\Route01.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetPos(825, 2450);
	AddGameObject(m_pPlayer);

	m_pWarp = new CWarp;
	m_pWarp->SetPos(825, 2550);
	m_pWarp->SetScale(100, 30);
	m_pWarp->SetDestination(GroupScene::PalletTown);
	AddGameObject(m_pWarp);

	m_pWarp2 = new CWarp;
	m_pWarp2->SetPos(750, 0);
	m_pWarp2->SetScale(300, 40);
	m_pWarp2->SetDestination(GroupScene::PalletTown);
	AddGameObject(m_pWarp2);

	LoadTile(GETPATH + L"Tile\\Route01.tile");
}

void CSceneRoute01::Enter()
{
	CAMERA->FadeIn(1.0f);
	CAMERA->SetTargetObj(m_pPlayer);
}

void CSceneRoute01::Update()
{
}

void CSceneRoute01::Render()
{
}

void CSceneRoute01::Exit()
{
}

void CSceneRoute01::Release()
{
}
