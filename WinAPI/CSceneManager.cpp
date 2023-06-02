#include "framework.h"
#include "CSceneManager.h"

//======== Scene ========
#include "CScene.h"
#include "CSceneTitle.h"
#include "CSceneTileTool.h"
#include "CSceneStage01.h"
#include "CScenePlayerHome2F.h"
#include "CScenePlayerHome1F.h"
#include "CScenePalletTown.h"
#include "CSceneOakLab.h"
#include "CSceneRoute01.h"
#include "CSceneViridianTown.h"
#include "CScenePokemonList.h"
#include "CSceneBattle.h"
#include "CSceneCenter.h"
#include "CSceneMountain.h"
//======== Scene ========

CSceneManager::CSceneManager()
{
	m_pCurScene = nullptr;
	m_pPrevScene = nullptr;
}

CSceneManager::~CSceneManager()
{
}

void CSceneManager::Init()
{
	// TODO : ���ӿ� �ʿ��� �� �߰�
	// ���Ӿ����� �ڷᱸ���� �߰�
	CScene* pSceneTitle = new CSceneTitle();
	m_mapScene.insert(make_pair(GroupScene::Title, pSceneTitle));
	CSceneTileTool* pSceneTileTool = new CSceneTileTool;
	m_mapScene.insert(make_pair(GroupScene::TileTool, pSceneTileTool));
	CScene* pSceneStage01 = new CSceneStage01();
	m_mapScene.insert(make_pair(GroupScene::Stage01, pSceneStage01));
	CScene* pPlayerHome2F = new CScenePlayerHome2F();
	m_mapScene.insert(make_pair(GroupScene::PlayerHome2F, pPlayerHome2F));
	CScene* pPlayerHome1F = new CScenePlayerHome1F();
	m_mapScene.insert(make_pair(GroupScene::PlayerHome1F, pPlayerHome1F));
	CScene* pPalletTown = new CScenePalletTown();
	m_mapScene.insert(make_pair(GroupScene::PalletTown, pPalletTown));
	CScene* pOakLab = new CSceneOakLab();
	m_mapScene.insert(make_pair(GroupScene::OakLab, pOakLab));
	CScene* pBattle = new CSceneBattle();
	m_mapScene.insert(make_pair(GroupScene::Battle, pBattle));
	CScene* pPokemonList = new CScenePokemonList();
	m_mapScene.insert(make_pair(GroupScene::PokemonList, pPokemonList));
	CScene* pRoute01 = new CSceneRoute01();
	m_mapScene.insert(make_pair(GroupScene::Route01, pRoute01));
	CScene* pViridianTown = new CSceneViridianTown();
	m_mapScene.insert(make_pair(GroupScene::ViridianTown, pViridianTown));
	CScene* pCenter = new CSceneCenter();
	m_mapScene.insert(make_pair(GroupScene::Center, pCenter));
	CScene* pMountain = new CSceneMountain();
	m_mapScene.insert(make_pair(GroupScene::Mountain, pMountain));

	// ���Ӿ� �ڷᱸ���� ��ȸ�ϸ� ���� �ʱ�ȭ
	for (pair<GroupScene, CScene*> scene : m_mapScene)
	{
		scene.second->SceneInit();
	}

	// ���� ó������ �����ؾ��� ���Ӿ� ����
	m_pCurScene = pSceneTitle;
	m_pCurScene->SceneEnter();
}

void CSceneManager::Update()
{
	m_pCurScene->SceneUpdate();
	m_pCurScene->ScenePhysicsUpdate();
}

void CSceneManager::Render()
{
	m_pCurScene->SceneRender();
}

void CSceneManager::Release()
{
	// ���Ӿ� �ڷᱸ���� ��ȸ�ϸ� �����Ҵ�� ���� ����
	for (pair<GroupScene, CScene*> scene : m_mapScene)
	{
		scene.second->SceneRelease();
		delete scene.second;
	}
	
	// ��� �����Ҵ�� ���� �����ѵ� �ڷᱸ���� clear
	m_mapScene.clear();
}

void CSceneManager::SwapScene()
{
	CScene* temp = m_pCurScene;
	m_pCurScene = m_pPrevScene;
	m_pPrevScene = temp;
}

void CSceneManager::ChangeScene(GroupScene scene)
{
	// �������� Exit, �������� Enter
	m_pPrevScene = m_pCurScene;
	m_pCurScene->SceneExit();
	m_pCurScene = m_mapScene[scene];
	m_pCurScene->SceneEnter();
}

void CSceneManager::ChangePrevScene()
{
	m_pCurScene->SceneExit();
	m_pPrevScene->SceneEnter();
	SwapScene();
}

CScene* CSceneManager::GetCurScene()
{
	return m_pCurScene;
}
