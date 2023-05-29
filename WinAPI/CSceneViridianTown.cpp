#include "framework.h"
#include "CSceneViridianTown.h"

#include "CPlayer.h"
#include "CWarp.h"

CSceneViridianTown::CSceneViridianTown()
{
	m_pImageBackGround	= nullptr;
	m_pPlayer			= nullptr;
	m_pWarp				= nullptr;
	m_pWarp2			= nullptr;
}

CSceneViridianTown::~CSceneViridianTown()
{
}

void CSceneViridianTown::Init()
{
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"ViridianTown", L"Image\\Map\\ViridianTown.png"));
	m_pImageBackGround->SetPos(0,0);
	AddGameObject(m_pImageBackGround);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetPos(1533, 2480);
	m_pPlayer->ChangeDir(PlayerDir::Up);
	AddGameObject(m_pPlayer);

	m_pWarp = new CWarp;
	m_pWarp->SetDestination(GroupScene::Route01); // 포켓몬센터
	m_pWarp->SetPos(1697, 1690);
	m_pWarp->SetScale(56, 25);
	AddGameObject(m_pWarp);

	m_pWarp2 = new CWarp;
	m_pWarp2->SetDestination(GroupScene::Route01);
	m_pWarp2->SetPos(1530, 2550);
	m_pWarp2->SetScale(270, 34);
	AddGameObject(m_pWarp2);

	LoadTile(GETPATH + L"Tile\\ViridianTown.tile");
}

void CSceneViridianTown::Enter()
{
	CAMERA->FadeIn(0.5f);
	CAMERA->SetTargetObj(m_pPlayer);
}

void CSceneViridianTown::Update()
{
}

void CSceneViridianTown::Render()
{
}

void CSceneViridianTown::Exit()
{
}

void CSceneViridianTown::Release()
{
	DELETEOBJECT(m_pImageBackGround);
	DELETEOBJECT(m_pPlayer);
	DELETEOBJECT(m_pWarp);
	DELETEOBJECT(m_pWarp2);
}
