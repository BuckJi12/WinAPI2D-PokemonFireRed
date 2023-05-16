#include "framework.h"
#include "CChangePokemonUI.h"


CChangePokemonUI::CChangePokemonUI()
{
	m_layer = Layer::Environment2;
	m_bar	= 0;
	m_color = Color(0, 255, 0, 1);

	m_pTargetPokemon = nullptr;
}

CChangePokemonUI::~CChangePokemonUI()
{
}

void CChangePokemonUI::SetTarget(CPokemon* pokemon)
{
	m_pTargetPokemon = pokemon;
}

void CChangePokemonUI::Init()
{
	m_pImage = RESOURCE->LoadImg(L"ChangePokemonUI", L"Image\\Battle\\ChangePokemonUI.png");
}

void CChangePokemonUI::Update()
{
	// 추후 옵저버 구독 방식으로 변경 예정 
	if (m_pTargetPokemon != nullptr)
	{
		m_bar = 152 * ((float)m_pTargetPokemon->GetPokemonStat().curHp /
			(float)m_pTargetPokemon->GetPokemonStat().maxHp);
	}
}

void CChangePokemonUI::Render()
{
	CImageObject::Render();

	if (m_pTargetPokemon != nullptr)
	{
		RENDER->Image(
			m_pTargetPokemon->GetPokemonResource()->GetIcon(),
			m_vecPos.x + 30,
			m_vecPos.y + 10,
			m_vecPos.x + 30 + (float)m_pTargetPokemon->GetPokemonResource()->GetIcon()->GetWidth(),
			m_vecPos.y + 10 + (float)m_pTargetPokemon->GetPokemonResource()->GetIcon()->GetHeight()
		);

		RENDER->Text(
			m_pTargetPokemon->GetPokemonInfo().name,
			m_vecPos.x + 120,
			m_vecPos.y + 15,
			m_vecPos.x + 220,
			m_vecPos.y + 45,
			Color(255, 255, 255, 1),
			25
		);

		RENDER->Text(
			L"LV  " + to_wstring(m_pTargetPokemon->GetPokemonStat().level),
			m_vecPos.x + 120,
			m_vecPos.y + 45,
			m_vecPos.x + 220,
			m_vecPos.y + 73,
			Color(255, 255, 255, 1),
			25
		);

		if (m_pTargetPokemon->GetPokemonStat().curHp >= 0)
		{
			RENDER->FillRect(
				m_vecPos.x + 302,
				m_vecPos.y + 32,
				m_vecPos.x + 302 + m_bar,
				m_vecPos.y + 43,
				m_color
			);
		}

		RENDER->Text(
			to_wstring(m_pTargetPokemon->GetPokemonStat().curHp) + L" / "
			+ to_wstring(m_pTargetPokemon->GetPokemonStat().maxHp),
			m_vecPos.x + 325,
			m_vecPos.y + 52,
			m_vecPos.x + 425,
			m_vecPos.y + 82,
			Color(255, 255, 255, 1),
			25
		);
	}
}

void CChangePokemonUI::Release()
{
}
