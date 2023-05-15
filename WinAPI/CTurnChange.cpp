#include "framework.h"
#include "CTurnChange.h"

#include "CImageObject.h"

CTurnChange::CTurnChange(CSceneBattle* battleScene) : CTurn(battleScene)
{
	m_pImagePokemonMenu = nullptr;
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
}

void CTurnChange::Enter()
{
	m_pImagePokemonMenu->SetPos(0, 0);
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
}

void CTurnChange::Release()
{
}
