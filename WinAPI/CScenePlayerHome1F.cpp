#include "framework.h"
#include "CScenePlayerHome1F.h"

#include "CPlayer.h"
#include "CImageObject.h"

CScenePlayerHome1F::CScenePlayerHome1F()
{
	m_pPlayer = nullptr;
	m_pImageBackGround = nullptr;
}

CScenePlayerHome1F::~CScenePlayerHome1F()
{
	delete m_pPlayer;
	delete m_pImageBackGround;
}

void CScenePlayerHome1F::Init()
{
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"PlayerHome1F", L"Image\\Map\\PlayerHome1F.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetPos(1000, 680);
	m_pPlayer->ChangeDir(PlayerDir::Left);
	AddGameObject(m_pPlayer);
}

void CScenePlayerHome1F::Enter()
{
	LoadTile(GETPATH + L"Tile\\PlayerHome1F.tile");
	CAMERA->FadeIn(0.25f);
	CAMERA->SetTargetObj(m_pPlayer);
}

void CScenePlayerHome1F::Update()
{
}

void CScenePlayerHome1F::Render()
{
}

void CScenePlayerHome1F::Exit()
{
}

void CScenePlayerHome1F::Release()
{
}
