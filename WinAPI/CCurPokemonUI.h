#pragma once
#include "CImageObject.h"

class CCurPokemonUI : public CImageObject
{
public:
	CCurPokemonUI();
	virtual ~CCurPokemonUI();

private:
	float m_bar;
	Color m_color;

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

