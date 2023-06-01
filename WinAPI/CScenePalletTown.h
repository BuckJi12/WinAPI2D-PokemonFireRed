#pragma once
class CPlayer;
class CImageObject;
class CWarp;

class CScenePalletTown : public CScene
{
public:
	CScenePalletTown();
	virtual ~CScenePalletTown();

private:
	CPlayer*		m_pPlayer;
	CImageObject*	m_pImageBackGround;
	CWarp*			m_pWarp;
	CWarp*			m_pWarp2;
	CWarp*			m_pWarp3;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

