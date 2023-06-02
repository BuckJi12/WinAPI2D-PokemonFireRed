#pragma once

class CWarp;
class CPlayer;
class CNPCMewtwo;

class CSceneMountain : public CScene
{
public:
	CSceneMountain();
	virtual ~CSceneMountain();

private:
	CImageObject*	m_pImageBackGround;
	CPlayer*		m_pPlayer;
	CWarp*			m_pWarpToViridian;
	CNPCMewtwo*		m_pNPCMewTwo;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

