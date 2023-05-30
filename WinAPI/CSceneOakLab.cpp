#include "framework.h"
#include "CSceneOakLab.h"

#include "CPlayer.h"
#include "CProfessorOak.h"
#include "CImageObject.h"
#include "CWarp.h"
#include "CTextBox.h"

CSceneOakLab::CSceneOakLab()
{
	m_pPlayer			= nullptr;
	m_pOak				= nullptr;
	m_pImageBackGround	= nullptr;
	m_pWarp				= nullptr;
	m_pTextBox			= nullptr;

	m_talking			= false;
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

	m_pTextBox = new CTextBox;
	m_pTextBox->SetPos(3000, 3000);
	AddGameObject(m_pTextBox);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetPos(700, 1000);
	AddGameObject(m_pPlayer);

	auto TalkingToOak = [](DWORD_PTR param)
	{
		CSceneOakLab* scene = (CSceneOakLab*)param;
		scene->m_pTextBox->SetText(L"오박사: 오 왔는가 현준 군!!\n마음에 드는 포켓몬을 한 마리 데려가게!");
		scene->m_pTextBox->SetPos(CAMERA->ScreenToWorldPoint(Vector(0, 400)));;
		scene->m_talking = true;
		// TODO: 행동 불가
	};

	m_pOak = new CProfessorOak;
	m_pOak->SetPos(738, 525);
	m_pOak->SetCallBack(TalkingToOak, (DWORD_PTR)this);
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
	CAMERA->SetTargetBackGround(m_pImageBackGround);
}

void CSceneOakLab::Update()
{
	if (m_talking)
	{
		if (BUTTONDOWN(VK_ESCAPE))
		{
			// TODO: 행동 가능
			m_talking = false;
			m_pTextBox->SetPos(CAMERA->WorldToScreenPoint(Vector(3000, 3000)));
		}
	}
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
