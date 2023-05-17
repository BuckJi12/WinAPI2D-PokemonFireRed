#pragma once
#include "CImageObject.h"

class CChangePokemonUI : public CImageObject
{
public:
	CChangePokemonUI();
	virtual ~CChangePokemonUI();

private:
	CPokemon* m_pTargetPokemon;

	float m_bar;
	Color m_color;

public:
	void		SetTarget(CPokemon* pokemon);
	CPokemon*	GetTarget();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

