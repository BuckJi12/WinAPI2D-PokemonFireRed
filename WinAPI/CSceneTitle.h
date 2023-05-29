#pragma once
#include "CScene.h"

class CTitleText;

class CSceneTitle : public CScene
{
public:
	CSceneTitle();
	virtual ~CSceneTitle();

private:
	CImageObject*	m_pImageBackGround;
	CTitleText*		m_titleText;
	CImageObject*	m_pSubTitle;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};
