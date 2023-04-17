#include "framework.h"
#include "CScenePlayerHome2F.h"

#include "CPlayer.h"
#include "CImageObject.h"

CScenePlayerHome2F::CScenePlayerHome2F()
{
	m_pPlayer = nullptr;
	m_pImageBackGround = nullptr;
}

CScenePlayerHome2F::~CScenePlayerHome2F()
{
	delete m_pPlayer;
	delete m_pImageBackGround;
}

void CScenePlayerHome2F::Init()
{
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"PlayerHome2F", L"Image\\Map\\PlayerHome2F.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetPos(800, 1000);
	AddGameObject(m_pPlayer);
}

void CScenePlayerHome2F::Enter()
{
	CAMERA->FadeIn(0.25f);
	CAMERA->SetTargetObj(m_pPlayer);
}

void CScenePlayerHome2F::Update()
{
}

void CScenePlayerHome2F::Render()
{
}

void CScenePlayerHome2F::Exit()
{
}

void CScenePlayerHome2F::Release()
{
}
