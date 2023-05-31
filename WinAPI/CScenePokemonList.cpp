#include "framework.h"
#include "CScenePokemonList.h"

#include "CCurPokemonUI.h"
#include "CSelectBox.h"

CScenePokemonList::CScenePokemonList()
{
	m_pBackGround	= nullptr;
	m_pSelectBox	= nullptr;
	m_pSelectedBox	= nullptr;

	m_pPokemonUI[0] = nullptr;
	m_pPokemonUI[1] = nullptr;
	m_pPokemonUI[2] = nullptr;
	m_pPokemonUI[3] = nullptr;
	m_pPokemonUI[4] = nullptr;
	m_pPokemonUI[5] = nullptr;

	m_curCount		= 0;
	m_first			= 0;
	m_second		= 0;
	m_firstCheck	= false;
	m_secondCheck	= false;
}

CScenePokemonList::~CScenePokemonList()
{
}

void CScenePokemonList::Setting()
{
	for (int i = 0; i < 6; i++)
	{
		if (i <= PLAYER->GetPlayerPokemonList().size() - 1)
		{
			m_pPokemonUI[i]->SetPokemon(PLAYER->GetPlayerPokemonList()[i]);
		}
		else
		{
			m_pPokemonUI[i]->SetPokemon(nullptr);
		}
	}

	m_curCount		= 0;
	m_curCount		= 0;
	m_first			= -1;
	m_second		= -1;
	m_firstCheck	= false;
	m_secondCheck	= false;
}

void CScenePokemonList::BoxControl()
{
	if (BUTTONDOWN(VK_RIGHT))
		m_curCount += 1;
	else if (BUTTONDOWN(VK_DOWN))
		m_curCount += 2;
	else if (BUTTONDOWN(VK_LEFT))
		m_curCount -= 1;
	else if (BUTTONDOWN(VK_UP))
		m_curCount -= 2;

	if (m_curCount >= PLAYER->GetPlayerPokemonList().size())
		m_curCount = 0;
	if (m_curCount < 0)
		m_curCount = PLAYER->GetPlayerPokemonList().size() - 1;

	switch (m_curCount)
	{
	case 0:
		m_pSelectBox->SetPos(121, 13);
		break;
	case 1:
		m_pSelectBox->SetPos(471, 13);
		break;
	case 2:
		m_pSelectBox->SetPos(121, 208);
		break;
	case 3:
		m_pSelectBox->SetPos(471, 208);
		break;
	case 4:
		m_pSelectBox->SetPos(121, 380);
		break;
	case 5:
		m_pSelectBox->SetPos(471, 380);
		break;
	}

	switch (m_first)
	{
	case 0:
		m_pSelectedBox->SetPos(121, 13);
		break;
	case 1:
		m_pSelectedBox->SetPos(471, 13);
		break;
	case 2:
		m_pSelectedBox->SetPos(121, 208);
		break;
	case 3:
		m_pSelectedBox->SetPos(471, 208);
		break;
	case 4:
		m_pSelectedBox->SetPos(121, 380);
		break;
	case 5:
		m_pSelectedBox->SetPos(471, 380);
		break;
	default:
		m_pSelectedBox->SetPos(1000, 1000);
		break;
	}
}

void CScenePokemonList::BoxSelect()
{
	if (BUTTONDOWN(VK_SPACE) && m_firstCheck)
	{
		if (m_firstCheck && !m_secondCheck)
		{
			m_second = m_curCount;
			m_secondCheck = true;
		}
	}

	if (BUTTONDOWN(VK_SPACE))
	{
		if (!m_firstCheck)
		{
			m_first = m_curCount;
			m_firstCheck = true;
		}
	}
}

void CScenePokemonList::SelectCancel()
{
	if (BUTTONDOWN(VK_ESCAPE) && m_firstCheck)
	{
		m_first = -1;
		m_firstCheck = false;
	}
}

void CScenePokemonList::PokemonChange()
{
	if (m_firstCheck && m_secondCheck)
	{
		if (m_first == m_second)
		{
			m_first = -1;
			m_firstCheck = false;
			m_second = -1;
			m_secondCheck = false;
			return;
		}

		// 포켓몬 변경
		PLAYER->PokemonSwap(m_first, m_second);
		m_pPokemonUI[m_first]->SetPokemon(PLAYER->GetPlayerPokemonList()[m_first]);
		m_pPokemonUI[m_second]->SetPokemon(PLAYER->GetPlayerPokemonList()[m_second]);
		m_first			= -1;
		m_firstCheck	= false;
		m_second		= -1;
		m_secondCheck	= false;
	}
}

void CScenePokemonList::DeletePokemon()
{
	if (BUTTONDOWN('D'))
	{
		PLAYER->DeletePokemon(m_curCount);
		Enter();
	}
}

void CScenePokemonList::Init()
{
	m_pBackGround = new CImageObject;
	m_pBackGround->SetImage(RESOURCE->LoadImg(L"PokemonList", L"Image\\UI\\PokemonList.png"));
	m_pBackGround->SetPos(0,0);
	m_pBackGround->SetLayer(Layer::Environment);
	AddGameObject(m_pBackGround);

	m_pSelectBox = new CSelectBox;
	m_pSelectBox->SetLayer(Layer::Environment);
	m_pSelectBox->SetPos(0,0);
	m_pSelectBox->SetColor(255, 0, 0);
	m_pSelectBox->SetSize(267, 191, 3);
	AddGameObject(m_pSelectBox);

	m_pSelectedBox = new CSelectBox;
	m_pSelectedBox->SetLayer(Layer::Environment);
	m_pSelectedBox->SetPos(0, 0);
	m_pSelectedBox->SetColor(0, 0, 255);
	m_pSelectedBox->SetSize(267, 191, 3);
	AddGameObject(m_pSelectedBox);

	m_pPokemonUI[0] = new CCurPokemonUI;
	m_pPokemonUI[0]->SetPos(100, -10);
	AddGameObject(m_pPokemonUI[0]);

	m_pPokemonUI[1] = new CCurPokemonUI;
	m_pPokemonUI[1]->SetPos(450, -10);
	AddGameObject(m_pPokemonUI[1]);

	m_pPokemonUI[2] = new CCurPokemonUI;
	m_pPokemonUI[2]->SetPos(100, 185);
	AddGameObject(m_pPokemonUI[2]);

	m_pPokemonUI[3] = new CCurPokemonUI;
	m_pPokemonUI[3]->SetPos(450, 185);
	AddGameObject(m_pPokemonUI[3]);

	m_pPokemonUI[4] = new CCurPokemonUI;
	m_pPokemonUI[4]->SetPos(100, 380);
	AddGameObject(m_pPokemonUI[4]);

	m_pPokemonUI[5] = new CCurPokemonUI;
	m_pPokemonUI[5]->SetPos(450, 380);
	AddGameObject(m_pPokemonUI[5]);
}

void CScenePokemonList::Enter()
{
	Setting();
}

void CScenePokemonList::Update()
{
	BoxControl();
	BoxSelect();
	PokemonChange();
	DeletePokemon();

	if (BUTTONDOWN(VK_ESCAPE) && !m_firstCheck && !m_secondCheck)
	{
		SCENE->ChangePrevScene();
	}
}

void CScenePokemonList::Render()
{
}

void CScenePokemonList::Exit()
{
}

void CScenePokemonList::Release()
{
	DELETEOBJECT(m_pBackGround);
	DELETEOBJECT(m_pSelectBox);
	DELETEOBJECT(m_pPokemonUI[0]);
	DELETEOBJECT(m_pPokemonUI[1]);
	DELETEOBJECT(m_pPokemonUI[2]);
	DELETEOBJECT(m_pPokemonUI[3]);
	DELETEOBJECT(m_pPokemonUI[4]);
	DELETEOBJECT(m_pPokemonUI[5]);
	
	delete[] m_pPokemonUI;
}
