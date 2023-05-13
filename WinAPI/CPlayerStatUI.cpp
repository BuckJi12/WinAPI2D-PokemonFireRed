#include "framework.h"
#include "CPlayerStatUI.h"

CPlayerStatUI::CPlayerStatUI()
{
	m_pCurPokemon	= nullptr;
	m_tempStat		= { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	m_value			= 0;
	m_color			= Color(0, 255, 0, 1);
	m_bar			= 0;
}

CPlayerStatUI::~CPlayerStatUI()
{
}

void CPlayerStatUI::SetPokemon(CPokemon* pokemon)
{
	m_pCurPokemon = pokemon;
	m_tempStat = pokemon->GetPokemonStat();
	UpdateUI();
}

void CPlayerStatUI::UpdateUI()
{
	// 지금 스텟에서 감소된 스텟의 차
	m_bar = 176 * ((float)m_pCurPokemon->GetPokemonStat().curHp / (float)m_pCurPokemon->GetPokemonStat().maxHp);
	m_value = m_tempStat.curHp - m_pCurPokemon->GetPokemonStat().curHp;

	while (m_tempStat.curHp > m_pCurPokemon->GetPokemonStat().curHp)
	{
		m_tempStat.curHp -= m_value * DT;
	}
}

void CPlayerStatUI::Init()
{
	m_pImage = RESOURCE->LoadImg(L"PlayerStatUI", L"Image\\Battle\\PlayerStatUI.png");
}

void CPlayerStatUI::Update()
{
	if (m_vecPos.x > 400)
		m_vecPos.x -= 600 * DT;

	if (m_tempStat.curHp > m_pCurPokemon->GetPokemonStat().curHp)
	{
		m_tempStat.curHp -= m_value * DT;
	}
}

void CPlayerStatUI::Render()
{
	CImageObject::Render();

	if (m_tempStat.curHp >= 0)
	{
		RENDER->FillRect(
			m_vecPos.x + 175,
			m_vecPos.y + 62,
			m_vecPos.x + 175 + m_bar,
			m_vecPos.y + 74,
			m_color
		);
	}

	RENDER->Text(
		m_pCurPokemon->GetPokemonInfo().name,
		m_vecPos.x + 50,
		m_vecPos.y + 10,
		m_vecPos.x + 180,
		m_vecPos.y + 50,
		Color(0, 0, 0, 1),
		25
	);

	RENDER->Text(
		to_wstring(m_pCurPokemon->GetPokemonStat().level),
		m_vecPos.x + 330,
		m_vecPos.y + 10,
		m_vecPos.x + 360,
		m_vecPos.y + 50,
		Color(0, 0, 0, 1),
		25
	);
}

void CPlayerStatUI::Release()
{
}

void CPlayerStatUI::ValueUpdate()
{
	UpdateUI();
}
