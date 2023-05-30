#include "framework.h"
#include "CSceneOakLab.h"

#include "CPlayer.h"
#include "CProfessorOak.h"
#include "CImageObject.h"
#include "CWarp.h"

CSceneOakLab::CSceneOakLab()
{
	m_pPlayer			= nullptr;
	m_pOak				= nullptr;
	m_pImageBackGround	= nullptr;
	m_pWarp				= nullptr;
}

CSceneOakLab::~CSceneOakLab()
{
	delete m_pPlayer;
	delete m_pImageBackGround;
	delete m_pWarp;
}

void CSceneOakLab::Init()
{
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"OakLab", L"Image\\Map\\OakLab.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetPos(700, 1000);
	AddGameObject(m_pPlayer);

	auto TalkingToOak = []()
	{
		Logger::Debug(L"박사님 날씨가 좋군요!");
	};

	m_pOak = new CProfessorOak;
	m_pOak->SetPos(738, 525);
	m_pOak->SetCallBack(TalkingToOak);
	AddGameObject(m_pOak);

	// 태초마을
	m_pWarp = new CWarp;
	m_pWarp->SetPos(700, 1150);
	m_pWarp->SetScale(100, 30);
	m_pWarp->SetDestination(GroupScene::PalletTown);
	AddGameObject(m_pWarp);

	LoadTile(GETPATH + L"Tile\\OakLab.tile");
}

void CSceneOakLab::Enter()
{
	CAMERA->FadeIn(1.0f);
	CAMERA->SetTargetObj(m_pPlayer);
}

void CSceneOakLab::Update()
{
}

void CSceneOakLab::Render()
{
}

void CSceneOakLab::Exit()
{
}

void CSceneOakLab::Release()
{
	DELETEOBJECT(m_pPlayer);
	DELETEOBJECT(m_pOak);
	DELETEOBJECT(m_pImageBackGround);
	DELETEOBJECT(m_pWarp);
}
