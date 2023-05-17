#include "framework.h"
#include "CTurnChange.h"

#include "CImageObject.h"
#include "CCurPokemonUI.h"
#include "CChangePokemonUI.h"

CTurnChange::CTurnChange(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pImagePokemonMenu		= nullptr;
	m_pImageCurPokemonUI	= nullptr;
	m_pImagePokemonUI1		= nullptr;
}

CTurnChange::~CTurnChange()
{
}

void CTurnChange::Init()
{
	m_pImagePokemonMenu = new CImageObject;
	m_pImagePokemonMenu->SetImage(RESOURCE->LoadImg(L"PokemonMenu", L"Image\\Battle\\PokemonMenu.png"));
	m_pImagePokemonMenu->SetPos(1000, 1000);
	m_pImagePokemonMenu->SetLayer(Layer::Environment);
	m_battleScene->AddObjectThisScene(m_pImagePokemonMenu);

	m_pImageCurPokemonUI = new CCurPokemonUI;
	m_pImageCurPokemonUI->SetPos(1000, 1000);
	m_pImageCurPokemonUI->Init();
	m_battleScene->AddObjectThisScene(m_pImageCurPokemonUI);

	m_pImagePokemonUI1 = new CChangePokemonUI;
	m_pImagePokemonUI1->SetPos(1000, 1000);
	m_pImagePokemonUI1->Init();
	m_pImagePokemonUI1->SetTarget(PLAYER->GetPlayerPokemonList()[1]);
	m_battleScene->AddObjectThisScene(m_pImagePokemonUI1);

}

void CTurnChange::Enter()
{
	m_pImagePokemonMenu->SetPos(0, 0);
	m_pImageCurPokemonUI->SetPos(3, 75);
	m_pImagePokemonUI1->SetPos(320, 30);
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
}

void CTurnChange::Release()
{
	DELETEOBJECT(m_pImagePokemonMenu);
	DELETEOBJECT(m_pImageCurPokemonUI);
}
