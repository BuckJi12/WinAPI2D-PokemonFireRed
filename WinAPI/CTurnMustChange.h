#pragma once
#include "CTurn.h"

class CCurPokemonUI;
class CChangePokemonUI;
class CSelectBox;

class CTurnMustChange : public CTurn
{
public:
	CTurnMustChange(CSceneBattle* battleScene);
	virtual ~CTurnMustChange();

private:
	CImageObject* m_pImagePokemonMenu;
	CCurPokemonUI* m_pImageCurPokemonUI;
	vector<CChangePokemonUI*>	m_vecPokemonUI;
	vector<Vector>				m_vecVector;
	queue<int>					m_queueIndexs;
	CSelectBox* m_pSelectBox;

	int							m_curCount;
	float						m_timer;
	bool						m_pokemonChanging;
	bool						m_phase1;
	bool						m_phase2;
	bool						m_phase3;

private:
	void Setting();
	void Reset();
	void SelectBoxControl();
	void SelectPokemon();
	void ChangePokemon();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

