#pragma once
class CPlayer;
class CImageObject;
class CWarp;
class CProfessorOak;
class CTextBox;
class CChoosePokemon;

class CSceneOakLab : public CScene
{
public:
	CSceneOakLab();
	virtual ~CSceneOakLab();

private:
	CPlayer*		m_pPlayer;
	CProfessorOak*	m_pOak;
	CImageObject*	m_pImageBackGround;
	CWarp*			m_pWarp;
	CTextBox*		m_pTextBox;
	CChoosePokemon* m_pChoosePokemon;
	bool			m_talking;
private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

