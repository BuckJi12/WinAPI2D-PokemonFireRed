#pragma once

class CCurPokemonUI;

class CScenePokemonList : public CScene
{
public:
	CScenePokemonList();
	virtual ~CScenePokemonList();

private:
	CImageObject*	m_pBackGround;
	CCurPokemonUI*	m_pPokemonUI[6];

private:
	void Setting();

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

