#pragma once
#include "CScene.h"

class CTitleText;
class CTitleAnimation;

class CSceneTitle : public CScene
{
public:
	CSceneTitle();
	virtual ~CSceneTitle();

private:
	CImageObject*		m_pImageBackGround;
	CTitleText*			m_titleText;
	CImageObject*		m_pSubTitle;
	CTitleAnimation*	m_pCharizardAni;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};
