#include "framework.h"
#include "CTurnChooseMove.h"

#include "CChooseMoveWindow.h"

CTurnChooseMove::CTurnChooseMove(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pImageChooseMove = nullptr;
	m_curCount = 0;
}

CTurnChooseMove::~CTurnChooseMove()
{
}

void CTurnChooseMove::CursorControl()
{
	if (BUTTONDOWN(VK_RIGHT))
		m_curCount += 1;
	else if (BUTTONDOWN(VK_DOWN))
		m_curCount += 2;
	else if (BUTTONDOWN(VK_LEFT))
		m_curCount -= 1;
	else if (BUTTONDOWN(VK_UP))
		m_curCount -= 2;

	if (m_curCount >= BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList().size())
		m_curCount = 0;

	if (m_curCount > 3)
	{
		if (m_curCount == 4)
			m_curCount = 0;
		else
			m_curCount = 1;
	}
	else if (m_curCount < 0)
	{
		if (m_curCount == -1)
			m_curCount = BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList().size() - 1;
	}

	if (BUTTONDOWN(VK_SPACE))
	{
		switch (m_curCount)
		{
		case 0:
			if (BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[0].GetMoveStat().curPP > 0)
			{
				BATTLE->SelectMove(BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[0]);
				//TODO: 선공 결정
				m_battleScene->ChangeTurn(PlayerAction::Battle);
			}
			break;
		case 1:
			if (BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[1].GetMoveStat().curPP > 0)
			{
				BATTLE->SelectMove(BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[1]);
				//TODO: 선공 결정
				m_battleScene->ChangeTurn(PlayerAction::Battle);
			}
			break;
		case 2:
			if (BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[2].GetMoveStat().curPP > 0)
			{
				BATTLE->SelectMove(BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[2]);
				//TODO: 선공 결정
				m_battleScene->ChangeTurn(PlayerAction::Battle);
			}
			break;
		case 3:
			if (BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[3].GetMoveStat().curPP > 0)
			{
				BATTLE->SelectMove(BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[3]);
				//TODO: 선공 결정
				m_battleScene->ChangeTurn(PlayerAction::Battle);
			}
			break;
		}
	}

	switch (m_curCount)
	{
	case 0:
		m_battleScene->GetCursor()->SetPos(20, 440);
		break;
	case 1:
		m_battleScene->GetCursor()->SetPos(240, 440);
		break;
	case 2:
		m_battleScene->GetCursor()->SetPos(20, 490);
		break;
	case 3:
		m_battleScene->GetCursor()->SetPos(240, 490);
		break;
	}
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
}

void CTurnChooseMove::Update()
{
	if (BUTTONDOWN(VK_ESCAPE))
		m_battleScene->ChangeTurn(PlayerAction::ChooseAction);

	CursorControl();
}

void CTurnChooseMove::Exit()
{
	m_pImageChooseMove->SetPos(1000, 1000);
}

void CTurnChooseMove::Release()
{
}
