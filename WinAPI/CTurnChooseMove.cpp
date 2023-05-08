#include "framework.h"
#include "CTurnChooseMove.h"

#include "CImageObject.h"

CTurnChooseMove::CTurnChooseMove(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pImageChooseMove = nullptr;
}

CTurnChooseMove::~CTurnChooseMove()
{
}

void CTurnChooseMove::CursorControl()
{
}

void CTurnChooseMove::Init()
{
	m_pImageChooseMove = new CImageObject;
	m_pImageChooseMove->SetImage(RESOURCE->LoadImg(L"ChooseMoveWindow", L"Image\\Battle\\ChooseMoveWindow.png"));
	m_pImageChooseMove->SetPos(1000, 1000);
	m_pImageChooseMove->SetLayer(Layer::Environment3);
	m_battleScene->AddObjectThisScene(m_pImageChooseMove);
}

void CTurnChooseMove::Enter()
{
	m_pImageChooseMove->SetPos(0, 400);
}

void CTurnChooseMove::Update()
{
}

void CTurnChooseMove::Exit()
{
	m_pImageChooseMove->SetPos(1000, 1000);
}

void CTurnChooseMove::Release()
{
}
