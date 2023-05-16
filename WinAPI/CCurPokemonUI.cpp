#include "framework.h"
#include "CCurPokemonUI.h"

CCurPokemonUI::CCurPokemonUI()
{
	m_layer = Layer::Environment2;
	m_bar = 164;
	m_color = Color(0, 255, 0, 1);
}

CCurPokemonUI::~CCurPokemonUI()
{
}

void CCurPokemonUI::Init()
{
	m_pImage = RESOURCE->LoadImg(L"CurPokemonUI",L"Image\\Battle\\CurPokemonUI.png");
}

void CCurPokemonUI::Update()
{
	// 추후 옵저버 구독 방식으로 변경 예정 
	m_bar = 164 * ((float)BATTLE->GetPlayerCurPokemon()->GetPokemonStat().curHp /
			(float)BATTLE->GetPlayerCurPokemon()->GetPokemonStat().maxHp);
}

void CCurPokemonUI::Render()
{
	CImageObject::Render();

	if (BATTLE->GetPlayerCurPokemon() != nullptr)
	{
		RENDER->Image(
			BATTLE->GetPlayerCurPokemon()->GetPokemonResource()->GetIcon(),
			m_vecPos.x + 20,
			m_vecPos.y + 20,
			m_vecPos.x + 20 + (float)BATTLE->GetPlayerCurPokemon()->GetPokemonResource()->GetIcon()->GetWidth(),
			m_vecPos.y + 20 + (float)BATTLE->GetPlayerCurPokemon()->GetPokemonResource()->GetIcon()->GetHeight()
		);

		RENDER->Text(
			BATTLE->GetPlayerCurPokemon()->GetPokemonInfo().name,
			m_vecPos.x + 120,
			m_vecPos.y + 60,
			m_vecPos.x + 220,
			m_vecPos.y + 80,
			Color(255, 255, 255, 1),
			25
		);

		RENDER->Text(
			L"LV  " + to_wstring(BATTLE->GetPlayerCurPokemon()->GetPokemonStat().level),
			m_vecPos.x + 120,
			m_vecPos.y + 100,
			m_vecPos.x + 220,
			m_vecPos.y + 120,
			Color(255, 255, 255, 1),
			25
		);

		if (BATTLE->GetPlayerCurPokemon()->GetPokemonStat().curHp >= 0)
		{
			RENDER->FillRect(
				m_vecPos.x + 103,
				m_vecPos.y + 152,
				m_vecPos.x + 103 + m_bar,
				m_vecPos.y + 163,
				m_color
			);
		}

		RENDER->Text(
			to_wstring(BATTLE->GetPlayerCurPokemon()->GetPokemonStat().curHp) + L" / "
			+ to_wstring(BATTLE->GetPlayerCurPokemon()->GetPokemonStat().maxHp),
			m_vecPos.x + 150,
			m_vecPos.y + 170,
			m_vecPos.x + 250,
			m_vecPos.y + 200,
			Color(255, 255, 255, 1),
			25
		);
	}
}

void CCurPokemonUI::Release()
{
}