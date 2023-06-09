#include "framework.h"
#include "COpponentStatUI.h"

#include "CImageObject.h"

COpponentStatUI::COpponentStatUI()
{
	m_pCurPokemon	= nullptr;
	m_tempStat		= {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	m_color			= Color(0 ,255 ,0 ,1);
	m_bar			= 0;
	m_value			= 0;
}

COpponentStatUI::~COpponentStatUI()
{
}

void COpponentStatUI::SetPokemon(CPokemon* pokemon)
{
	m_pCurPokemon = pokemon;
	m_tempStat = pokemon->GetPokemonStat();
	UpdateUI();
}

void COpponentStatUI::UpdateUI()
{
	// 지금 스텟에서 감소된 스텟의 차
	m_bar = 183 * ((float)m_pCurPokemon->GetPokemonStat().curHp / (float)m_pCurPokemon->GetPokemonStat().maxHp);
	m_value = (float)(m_tempStat.curHp - m_pCurPokemon->GetPokemonStat().curHp) / 10.0f;

	if (m_pCurPokemon->GetPokemonStat().curHp < ((float)m_pCurPokemon->GetPokemonStat().maxHp / 1.5))
		m_color = Color(255, 255, 0, 1);
	else if (m_pCurPokemon->GetPokemonStat().curHp < (m_pCurPokemon->GetPokemonStat().maxHp / 4))
		m_color = Color(255, 0, 0, 1);
	else
		m_color = Color(0, 255, 0, 1);
}

void COpponentStatUI::Init()
{
	m_pImage = RESOURCE->LoadImg(L"OpponentStatUI", L"Image\\Battle\\OpponentStatUI.png");
}

void COpponentStatUI::Update()
{
	if (m_vecPos.x < 75)
		m_vecPos.x += 600 * DT;

	if (m_tempStat.curHp > m_pCurPokemon->GetPokemonStat().curHp)
	{
		m_tempStat.curHp -= m_value * DT;
	}
}

void COpponentStatUI::Render()
{
	CImageObject::Render();

	if (m_tempStat.curHp >= 0)
	{
		RENDER->FillRect(
			m_vecPos.x + 148,
			m_vecPos.y + 64,
			m_vecPos.x + 148 + m_bar,
			m_vecPos.y + 76,
			m_color
		);
	}

	RENDER->Text(
		m_pCurPokemon->GetPokemonInfo().name,
		m_vecPos.x + 30,
		m_vecPos.y + 10,
		m_vecPos.x + 150,
		m_vecPos.y + 50,
		Color(0, 0, 0, 1),
		25
	);

	RENDER->Text(
		to_wstring(m_pCurPokemon->GetPokemonStat().level),
		m_vecPos.x + 310,
		m_vecPos.y + 10,
		m_vecPos.x + 340,
		m_vecPos.y + 50,
		Color(0, 0, 0, 1),
		25
	);
}

void COpponentStatUI::Release()
{
}

void COpponentStatUI::ValueUpdate()
{
	UpdateUI();
}
