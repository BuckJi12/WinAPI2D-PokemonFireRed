#include "framework.h"
#include "CTurnChooseMove.h"

#include "CChooseMoveWindow.h"

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
	m_pImageChooseMove = new CChooseMoveWindow;
	m_pImageChooseMove->Init();
	m_pImageChooseMove->SetPos(1000, 1000);
	m_battleScene->AddObjectThisScene(m_pImageChooseMove);
}

void CTurnChooseMove::Enter()
{
	m_pImageChooseMove->SetPos(0, 400);
	Logger::Debug(to_wstring(PLAYER->GetPlayerPokemonList()[0]->GetPokemonMoveList().size()));
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
