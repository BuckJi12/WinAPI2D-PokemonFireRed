#pragma once
#include "CTurn.h"

class CCurPokemonUI;
class CChangePokemonUI;
class CSelectBox;

class CTurnChange : public CTurn
{
public:
	CTurnChange(CSceneBattle* battleScene);
	virtual ~CTurnChange();

private:
	CImageObject*				m_pImagePokemonMenu;
	CCurPokemonUI*				m_pImageCurPokemonUI;
	vector<CChangePokemonUI*>	m_vecPokemonUI;
	vector<Vector>				m_vecVector;
	queue<int>					m_queueIndexs;
	CSelectBox*					m_pSelectBox;

private:
	void Setting();
	void Reset();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

