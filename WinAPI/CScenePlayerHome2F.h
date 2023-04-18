#pragma once
#include "CScene.h"

class CPlayer;
class CImageObject;
class CWarp;

class CScenePlayerHome2F : public CScene
{
public:
	CScenePlayerHome2F();
	virtual ~CScenePlayerHome2F();

private:
	CPlayer*		m_pPlayer;
	CImageObject*	m_pImageBackGround;
	CWarp*			m_pWarp;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

