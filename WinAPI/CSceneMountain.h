#pragma once

class CWarp;
class CPlayer;

class CSceneMountain : public CScene
{
public:
	CSceneMountain();
	virtual ~CSceneMountain();

private:
	CImageObject*	m_pImageBackGround;
	CPlayer*		m_pPlayer;
	CWarp*			m_pWarpToViridian;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

