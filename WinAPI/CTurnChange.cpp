#include "framework.h"
#include "CTurnChange.h"

#include "CImageObject.h"
#include "CSelectBox.h"
#include "CCurPokemonUI.h"
#include "CChangePokemonUI.h"

CTurnChange::CTurnChange(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pImagePokemonMenu		= nullptr;
	m_pImageCurPokemonUI	= nullptr;
	m_pSelectBox			= nullptr;
}

CTurnChange::~CTurnChange()
{
}

void CTurnChange::Setting()
{
	for (int i = 0; i < PLAYER->GetPlayerPokemonList().size(); i++)
	{
		if (PLAYER->GetPlayerPokemonList()[i] == BATTLE->GetPlayerCurPokemon())
			continue;

		m_queueIndexs.push(i);
	}

	for (int i = 0; !m_queueIndexs.empty(); i++)
	{
		m_vecPokemonUI[i]->SetTarget(PLAYER->GetPlayerPokemonList()[m_queueIndexs.front()]);
		m_vecPokemonUI[i]->SetPos(m_vecVector[i]);
		m_queueIndexs.pop();
	}
}

void CTurnChange::Reset()
{
	for (auto pokemonUI : m_vecPokemonUI)
	{
		pokemonUI->SetPos(1000,1000);
		pokemonUI->SetTarget(nullptr);
	}
}

void CTurnChange::Init()
{
	m_pImagePokemonMenu = new CImageObject;
	m_pImagePokemonMenu->SetImage(RESOURCE->LoadImg(L"PokemonMenu", L"Image\\Battle\\PokemonMenu.png"));
	m_pImagePokemonMenu->SetPos(1000, 1000);
	m_pImagePokemonMenu->SetLayer(Layer::Environment);
	m_battleScene->AddObjectThisScene(m_pImagePokemonMenu);

	m_pSelectBox = new CSelectBox;
	m_pSelectBox->SetSize(473, 88, 3);
	m_pSelectBox->SetColor(255,127,0);
	m_pSelectBox->SetPos(1000, 1000);
	m_battleScene->AddObjectThisScene(m_pSelectBox);

	m_pImageCurPokemonUI = new CCurPokemonUI;
	m_pImageCurPokemonUI->SetPos(1000, 1000);
	m_pImageCurPokemonUI->Init();
	m_battleScene->AddObjectThisScene(m_pImageCurPokemonUI);

	CChangePokemonUI* m_pImagePokemonUI1 = new CChangePokemonUI;
	m_pImagePokemonUI1->SetPos(1000, 1000);
	m_pImagePokemonUI1->Init();
	m_battleScene->AddObjectThisScene(m_pImagePokemonUI1);

	CChangePokemonUI* m_pImagePokemonUI2 = new CChangePokemonUI;
	m_pImagePokemonUI2->SetPos(1000, 1000);
	m_pImagePokemonUI2->Init();
	m_battleScene->AddObjectThisScene(m_pImagePokemonUI2);

	CChangePokemonUI* m_pImagePokemonUI3 = new CChangePokemonUI;
	m_pImagePokemonUI3->SetPos(1000, 1000);
	m_pImagePokemonUI3->Init();
	m_battleScene->AddObjectThisScene(m_pImagePokemonUI3);

	CChangePokemonUI* m_pImagePokemonUI4 = new CChangePokemonUI;
	m_pImagePokemonUI4->SetPos(1000, 1000);
	m_pImagePokemonUI4->Init();
	m_battleScene->AddObjectThisScene(m_pImagePokemonUI4);

	CChangePokemonUI* m_pImagePokemonUI5 = new CChangePokemonUI;
	m_pImagePokemonUI5->SetPos(1000, 1000);
	m_pImagePokemonUI5->Init();
	m_battleScene->AddObjectThisScene(m_pImagePokemonUI5);

	m_vecPokemonUI.push_back(m_pImagePokemonUI1);
	m_vecPokemonUI.push_back(m_pImagePokemonUI2);
	m_vecPokemonUI.push_back(m_pImagePokemonUI3);
	m_vecPokemonUI.push_back(m_pImagePokemonUI4);
	m_vecPokemonUI.push_back(m_pImagePokemonUI5);

	m_vecVector.push_back(Vector(320, 30));
	m_vecVector.push_back(Vector(320, 123));
	m_vecVector.push_back(Vector(320, 213));
	m_vecVector.push_back(Vector(320, 303));
	m_vecVector.push_back(Vector(320, 393));
}

void CTurnChange::Enter()
{
	m_pImagePokemonMenu->SetPos(0, 0);
	m_pImageCurPokemonUI->SetPos(3, 75);
	m_pSelectBox->SetPos(320, 30);
	Setting();
}

void CTurnChange::Update()
{
	if (BUTTONDOWN(VK_ESCAPE))
	{
		m_battleScene->ChangeTurn(PlayerAction::ChooseAction);
	}
}

void CTurnChange::Exit()
{
	m_pImagePokemonMenu->SetPos(1000, 1000);
	m_pImageCurPokemonUI->SetPos(1000, 1000);
	Reset();
}

void CTurnChange::Release()
{
	DELETEOBJECT(m_pImagePokemonMenu);
	DELETEOBJECT(m_pImageCurPokemonUI);
}
