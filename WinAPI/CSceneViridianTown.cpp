#include "framework.h"
#include "CSceneViridianTown.h"

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
	m_pImageBackGround->SetLayer(Layer::Environment);
	AddGameObject(m_pImageBackGround);
}

void CSceneViridianTown::Enter()
{
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
}
