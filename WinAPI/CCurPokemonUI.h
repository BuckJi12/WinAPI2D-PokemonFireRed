#pragma once
#include "CImageObject.h"

class CCurPokemonUI : public CImageObject
{
public:
	CCurPokemonUI();
	virtual ~CCurPokemonUI();

private:
	CPokemon*	m_targetPokemon;
	float		m_bar;
	Color		m_color;

public:
	void SetPokemon(CPokemon* pokemon);

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

