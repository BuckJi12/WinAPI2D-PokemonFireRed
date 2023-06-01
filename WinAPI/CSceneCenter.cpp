#include "framework.h"
#include "CSceneCenter.h"

#include "CPlayer.h"
#include "CWarp.h"
#include "CNurse.h"

CSceneCenter::CSceneCenter()
{
	m_pImageBackGround	= nullptr;
	m_pPlayer			= nullptr;
	m_pWarp				= nullptr;
	m_pNurse			= nullptr;
}

CSceneCenter::~CSceneCenter()
{
}

void CSceneCenter::Init()
{
	m_pImageBackGround = new CImageObject;
	m_pImageBackGround->SetPos(0, 0);
	m_pImageBackGround->SetImage(RESOURCE->LoadImg(L"PokemonCenter", L"Image\\map\\PokemonCenter.png"));
	AddGameObject(m_pImageBackGround);

	m_pPlayer = new CPlayer;
	m_pPlayer->SetPos(800, 1020);
	m_pPlayer->ChangeDir(PlayerDir::Up);
	AddGameObject(m_pPlayer);

	m_pWarp = new CWarp;
	m_pWarp->SetDestination(GroupScene::ViridianTown); // 포켓몬센터
	m_pWarp->SetPos(798, 1086);
	m_pWarp->SetScale(106, 32);
	AddGameObject(m_pWarp);

	auto recoverPokemon = [](DWORD_PTR param)
	{
		PLAYER->RecoverPokemon();
	};

	m_pNurse = new CNurse;
	m_pNurse->SetPos(800, 650);
	m_pNurse->SetCallBack(recoverPokemon, (DWORD_PTR)this);
	AddGameObject(m_pNurse);

	LoadTile(GETPATH + L"Tile\\Center.tile");
}

void CSceneCenter::Enter()
{
	CAMERA->FadeIn(0.5f);
	CAMERA->SetTargetObj(m_pPlayer);
	CAMERA->SetTargetBackGround(m_pImageBackGround);
	SOUND->Play(SOUND->GetBGM(GroupScene::Center), 0.2f, true);
}

void CSceneCenter::Update()
{
}

void CSceneCenter::Render()
{
}

void CSceneCenter::Exit()
{
	SOUND->Stop(SOUND->GetBGM(GroupScene::Center));
}

void CSceneCenter::Release()
{
	DELETEOBJECT(m_pImageBackGround);
	DELETEOBJECT(m_pPlayer);
	DELETEOBJECT(m_pWarp);
	DELETEOBJECT(m_pNurse);
}
