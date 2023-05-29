#pragma once

class CCurPokemonUI;
class CSelectBox;

class CScenePokemonList : public CScene
{
public:
	CScenePokemonList();
	virtual ~CScenePokemonList();

private:
	CImageObject*	m_pBackGround;
	CSelectBox*		m_pSelectBox;
	CSelectBox*		m_pSelectedBox;
	CCurPokemonUI*	m_pPokemonUI[6];

	int				m_curCount;
	int				m_first;
	int				m_second;
	bool			m_firstCheck;
	bool			m_secondCheck;

private:
	void Setting();
	void BoxControl();
	void BoxSelect();
	void SelectCancel();
	void PokemonChange();

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

