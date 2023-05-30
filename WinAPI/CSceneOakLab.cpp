#include "framework.h"
#include "CSceneOakLab.h"

#include "CPlayer.h"
#include "CProfessorOak.h"
#include "CImageObject.h"
#include "CWarp.h"
#include "CTextBox.h"
#include "CChoosePokemon.h"
#include "CPokemonFrame.h"

CSceneOakLab::CSceneOakLab()
{
	m_pPlayer			= nullptr;
	m_pOak				= nullptr;
	m_pImageBackGround	= nullptr;
	m_pWarp				= nullptr;
	m_pTextBox			= nullptr;
	m_pChoosePokemon	= nullptr;

	m_pPokemonFrame[0]	= nullptr;
	m_pPokemonFrame[1]	= nullptr;
	m_pPokemonFrame[2]	= nullptr;

	m_curCount			= 0;
	m_choosing			= false;
	m_talking			= false;
}

CSceneOakLab::~CSceneOakLab()
{
	delete m_pPlayer;
	delete m_pImageBackGround;
	delete m_pWarp;
}

void CSceneOakLab::PokemonChoosing()
{
	if (m_choosing)
	{
		if (BUTTONDOWN(VK_ESCAPE))
		{
			GAME->SetCanMove(true);
			m_choosing = false;
		}

		FrameControl();
		FrameSelcet();
	}
}

void CSceneOakLab::FrameControl()
{
	if (BUTTONDOWN(VK_LEFT))
		m_curCount -= 1;
	else if (BUTTONDOWN(VK_RIGHT))
		m_curCount += 1;

	if (m_curCount > 2)
		m_curCount = 0;
	if (m_curCount < 0)
		m_curCount = 2;

	switch (m_curCount)
	{
	case 0:
		m_pPokemonFrame[0]->SetPos(CAMERA->ScreenToWorldPoint(Vector(400, 200)));
		m_pPokemonFrame[1]->SetPos(3000, 3000);
		m_pPokemonFrame[2]->SetPos(3000, 3000);
		m_pTextBox->SetText(L"풀 타입 포켓몬 이상해씨로 선택하시겠습니까?");
		break;
	case 1:
		m_pPokemonFrame[0]->SetPos(3000, 3000);
		m_pPokemonFrame[1]->SetPos(CAMERA->ScreenToWorldPoint(Vector(400, 200)));
		m_pPokemonFrame[2]->SetPos(3000, 3000);
		m_pTextBox->SetText(L"불꽃 타입 포켓몬 파이리로 선택하시겠습니까?");
		break;
	case 2:
		m_pPokemonFrame[0]->SetPos(3000, 3000);
		m_pPokemonFrame[1]->SetPos(3000, 3000);
		m_pPokemonFrame[2]->SetPos(CAMERA->ScreenToWorldPoint(Vector(400, 200)));
		m_pTextBox->SetText(L"물 타입 꼬부기로 선택하시겠습니까?");
		break;
	}
}

void CSceneOakLab::FrameSelcet()
{
	if (BUTTONDOWN(VK_SPACE))
	{
		m_choosing = false;
		m_pPokemonFrame[0]->SetPos(3000, 3000);
		m_pPokemonFrame[1]->SetPos(3000, 3000);
		m_pPokemonFrame[2]->SetPos(3000, 3000);
		m_pTextBox->SetPos(3000, 3000);
		GAME->SetCanMove(true);
		GAME->SetPlayerGetStarting(true);
		GivePokemon(m_curCount);
	}
}

void CSceneOakLab::GivePokemon(int index)
{
	if (index == 0)	// 이상해씨
	{
		CPokemon* pokemon = new CPokemon(*POKEMON->FindPokemon(1));
		pokemon->SetPokemonStat(5);
		PLAYER->AddPokemonToPlayer(pokemon);
	}
	else if (index == 1) // 파이리
	{
		CPokemon* pokemon = new CPokemon(*POKEMON->FindPokemon(4));
		pokemon->SetPokemonStat(5);
		PLAYER->AddPokemonToPlayer(pokemon);
	}
	else // 꼬부기
	{
		CPokemon* pokemon = new CPokemon(*POKEMON->FindPokemon(7));
		pokemon->SetPokemonStat(5);
		PLAYER->AddPokemonToPlayer(pokemon);
	}
}

void CSceneOakLab::Init()
{
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"OakLab", L"Image\\Map\\OakLab.png"));
	m_pImageBackGround->SetPos(0, 0);
	AddGameObject(m_pImageBackGround);

	m_pTextBox = new CTextBox;
	m_pTextBox->SetPos(3000, 3000);
	AddGameObject(m_pTextBox);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetPos(700, 1000);
	AddGameObject(m_pPlayer);

	auto TalkingToOak = [](DWORD_PTR param)
	{
		CSceneOakLab* scene = (CSceneOakLab*)param;
		scene->m_pTextBox->SetText(L"오박사: 오 왔는가 현준 군!!\n마음에 드는 포켓몬을 한 마리 데려가게!");
		scene->m_pTextBox->SetPos(CAMERA->ScreenToWorldPoint(Vector(0, 400)));;
		scene->m_talking = true;
		GAME->SetCanMove(false);
	};

	m_pOak = new CProfessorOak;
	m_pOak->SetPos(738, 525);
	m_pOak->SetCallBack(TalkingToOak, (DWORD_PTR)this);
	AddGameObject(m_pOak);

	auto TalkingToChoosePokemon = [](DWORD_PTR param)
	{
		if (GAME->GetPlayerGetStarting() == false)
		{
			CSceneOakLab* scene = (CSceneOakLab*)param;
			scene->m_pTextBox->SetPos(CAMERA->ScreenToWorldPoint(Vector(0, 400)));;
			scene->m_choosing = true;
			GAME->SetCanMove(false);
		}
	};


	m_pChoosePokemon = new CChoosePokemon;
	m_pChoosePokemon->SetPos(925, 627);
	m_pChoosePokemon->SetCallBack(TalkingToChoosePokemon, (DWORD_PTR)this);
	AddGameObject(m_pChoosePokemon);

	m_pPokemonFrame[0] = new CPokemonFrame;
	m_pPokemonFrame[0]->SetImage(RESOURCE->LoadImg(L"BulbasaurImage", L"Image\\Pokemon\\Bulbasaur.png"));
	m_pPokemonFrame[0]->SetPos(3000, 3000);
	AddGameObject(m_pPokemonFrame[0]);

	m_pPokemonFrame[1] = new CPokemonFrame;
	m_pPokemonFrame[1]->SetImage(RESOURCE->LoadImg(L"CharmanderImage", L"Image\\Pokemon\\Charmander.png"));
	m_pPokemonFrame[1]->SetPos(3000, 3000);
	AddGameObject(m_pPokemonFrame[1]);

	m_pPokemonFrame[2] = new CPokemonFrame;
	m_pPokemonFrame[2]->SetImage(RESOURCE->LoadImg(L"SquirtleImage", L"Image\\Pokemon\\Squirtle.png"));
	m_pPokemonFrame[2]->SetPos(3000, 3000);
	AddGameObject(m_pPokemonFrame[2]);

	// 태초마을
	m_pWarp = new CWarp;
	m_pWarp->SetPos(700, 1150);
	m_pWarp->SetScale(100, 30);
	m_pWarp->SetDestination(GroupScene::PalletTown);
	AddGameObject(m_pWarp);

	LoadTile(GETPATH + L"Tile\\OakLab.tile");
}

void CSceneOakLab::Enter()
{
	CAMERA->FadeIn(1.0f);
	CAMERA->SetTargetObj(m_pPlayer);
	CAMERA->SetTargetBackGround(m_pImageBackGround);
}

void CSceneOakLab::Update()
{
	if (m_talking)
	{
		if (BUTTONDOWN(VK_SPACE))
		{
			GAME->SetCanMove(true);
			m_talking = false;
			m_pTextBox->SetPos(CAMERA->WorldToScreenPoint(Vector(3000, 3000)));
		}
	}

	PokemonChoosing();
}

void CSceneOakLab::Render()
{
}

void CSceneOakLab::Exit()
{
}

void CSceneOakLab::Release()
{
	DELETEOBJECT(m_pPlayer);
	DELETEOBJECT(m_pOak);
	DELETEOBJECT(m_pTextBox);
	DELETEOBJECT(m_pImageBackGround);
	DELETEOBJECT(m_pWarp);
	DELETEOBJECT(m_pChoosePokemon);
}
