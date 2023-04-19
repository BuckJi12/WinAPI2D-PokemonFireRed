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
//======== Scene ========

CSceneManager::CSceneManager()
{
	m_pCurScene = nullptr;
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

void CSceneManager::ChangeScene(GroupScene scene)
{
	// �������� Exit, �������� Enter
	m_pCurScene->SceneExit();
	m_pCurScene = m_mapScene[scene];
	m_pCurScene->SceneEnter();
}

CScene* CSceneManager::GetCurScene()
{
	return m_pCurScene;
}
