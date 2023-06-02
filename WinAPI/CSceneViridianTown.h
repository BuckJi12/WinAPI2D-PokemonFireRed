#pragma once

class CPlayer;
class CWarp;

class CSceneViridianTown : public CScene
{
public:
	CSceneViridianTown();
	virtual ~CSceneViridianTown();

private:
	CImageObject*	m_pImageBackGround;
	CPlayer*		m_pPlayer;
	CWarp*			m_pWarp;
	CWarp*			m_pWarp2;
	CWarp*			m_pWarpToMountain;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

