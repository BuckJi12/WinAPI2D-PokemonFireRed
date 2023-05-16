#pragma once
#include "CTurn.h"

class CCurPokemonUI;
class CChangePokemonUI;

class CTurnChange : public CTurn
{
public:
	CTurnChange(CSceneBattle* battleScene);
	virtual ~CTurnChange();

private:
	CImageObject*		m_pImagePokemonMenu;
	CCurPokemonUI*		m_pImageCurPokemonUI;
	CChangePokemonUI*	m_pImagePokemonUI1;

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

