#pragma once
#include "WinAPI.h"

class CCore;
class CEventManager;
class CCollisionManager;
class CUIManager;
class CScene;

class CSceneManager : public SingleTon<CSceneManager>
{
	friend SingleTon<CSceneManager>;
	friend CCore;
	friend CEventManager;
	friend CCollisionManager;
	friend CUIManager;
private:
	CSceneManager();
	virtual ~CSceneManager();

	map<GroupScene, CScene*> m_mapScene;	// ���Ӿ����� �����ϴ� �ڷᱸ��
	CScene* m_pCurScene;					// ���� ���Ӿ�
	CScene* m_pPrevScene;

	void Init();
	void Update();
	void Render();
	void Release();
	void SwapScene();

public:
	CScene* GetCurScene();					// ���� ���Ӿ� ��ȯ
	void ChangeScene(GroupScene scene);		// ���Ӿ� ����
	void ChangePrevScene();
};

#define SCENE				CSceneManager::GetInstance()