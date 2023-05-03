#pragma once
#include "CImageObject.h"

class COpponentStatUI : public CImageObject, public IObserver
{
public:
	COpponentStatUI();
	virtual ~COpponentStatUI();

private:
	CPokemon* m_pCurPokemon;
	PokemonStat m_tempStat;
	Color m_color;

	float m_bar;
public:
	void SetPokemon(CPokemon* pokemon);

private:
	void UpdateUI();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;		
	void Release()	override;		


	void ValueUpdate() override; // 옵저버 업데이트
};

