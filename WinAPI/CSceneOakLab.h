#pragma once
class CPlayer;
class CImageObject;
class CWarp;
class CProfessorOak;
class CTextBox;
class CChoosePokemon;
class CPokemonFrame;

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
	CPokemonFrame*	m_pPokemonFrame[3];

	int				m_curCount;
	bool			m_choosing;
	bool			m_talking;

private:
	void PokemonChoosing();
	void FrameControl();
	void FrameSelcet();

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

