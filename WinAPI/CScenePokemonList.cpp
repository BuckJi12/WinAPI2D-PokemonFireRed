#include "framework.h"
#include "CScenePokemonList.h"

#include "CCurPokemonUI.h"

CScenePokemonList::CScenePokemonList()
{
	m_pBackGround	= nullptr;

	m_pPokemonUI[0] = nullptr;
	m_pPokemonUI[1] = nullptr;
	m_pPokemonUI[2] = nullptr;
	m_pPokemonUI[3] = nullptr;
	m_pPokemonUI[4] = nullptr;
	m_pPokemonUI[5] = nullptr;
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
}

void CScenePokemonList::Init()
{
	m_pBackGround = new CImageObject;
	m_pBackGround->SetImage(RESOURCE->LoadImg(L"PokemonList", L"Image\\UI\\PokemonList.png"));
	m_pBackGround->SetPos(0,0);
	m_pBackGround->SetLayer(Layer::Environment);
	AddGameObject(m_pBackGround);

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
	if (BUTTONDOWN(VK_ESCAPE))
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
}
