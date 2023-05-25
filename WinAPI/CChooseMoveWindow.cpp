#include "framework.h"
#include "CChooseMoveWindow.h"

CChooseMoveWindow::CChooseMoveWindow()
{
	m_layer		= Layer::Environment2;
	m_curCount	= 0;
}

CChooseMoveWindow::~CChooseMoveWindow()
{
}

void CChooseMoveWindow::SetCount(int num)
{
	m_curCount = num;
}

void CChooseMoveWindow::Init()
{
	m_pImage = RESOURCE->LoadImg(L"ChooseMoveWindow", L"Image\\Battle\\ChooseMoveWindow.png");
}

void CChooseMoveWindow::Update()
{
}

void CChooseMoveWindow::Render()
{
	CImageObject::Render();

	RENDER->Text(
		BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[0]->GetMoveStat().name,
		m_vecPos.x + 75,
		m_vecPos.y + 50,
		m_vecPos.x + 300,
		m_vecPos.y + 100,
		Color(0, 0, 0, 1),
		25
	);

	if (BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList().size() > 1)
	{
		RENDER->Text(
			BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[1]->GetMoveStat().name,
			m_vecPos.x + 300,
			m_vecPos.y + 50,
			m_vecPos.x + 600,
			m_vecPos.y + 100,
			Color(0, 0, 0, 1),
			25
		);
	}

	if (BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList().size() > 2)
	{
		RENDER->Text(
			BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[2]->GetMoveStat().name,
			m_vecPos.x + 75,
			m_vecPos.y + 100,
			m_vecPos.x + 300,
			m_vecPos.y + 150,
			Color(0, 0, 0, 1),
			25
		);
	}

	if (BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList().size() > 3)
	{
		RENDER->Text(
			BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[3]->GetMoveStat().name,
			m_vecPos.x + 300,
			m_vecPos.y + 100,
			m_vecPos.x + 600,
			m_vecPos.y + 150,
			Color(0, 0, 0, 1),
			25
		);
	}

	RENDER->Text(
		to_wstring(BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[m_curCount]->GetMoveStat().curPP)
		+ L" / "
		+ to_wstring(BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[m_curCount]->GetMoveStat().maxPP),
		m_vecPos.x + 650,
		m_vecPos.y + 35,
		m_vecPos.x + 800,
		m_vecPos.y + 100,
		Color(0, 0, 0, 1),
		25
	);

	RENDER->Text(
		BATTLE->GetPlayerCurPokemon()->GetPokemonMoveList()[m_curCount]->GetMoveStat().moveType,
		m_vecPos.x + 650,
		m_vecPos.y + 100,
		m_vecPos.x + 800,
		m_vecPos.y + 150,
		Color(0, 0, 0, 1),
		25
	);
}

void CChooseMoveWindow::Release()
{
}
