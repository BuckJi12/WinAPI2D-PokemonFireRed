#pragma once

class CPlayer;
class CWarp;

class CSceneCenter : public CScene
{
public:
	CSceneCenter();
	virtual ~CSceneCenter();

private:
	CImageObject*	m_pImageBackGround;
	CPlayer*		m_pPlayer;
	CWarp*			m_pWarp;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

