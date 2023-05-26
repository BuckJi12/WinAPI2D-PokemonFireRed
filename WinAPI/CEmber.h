#pragma once

class CEmber : public CMove
{
public:
	CEmber();
	virtual ~CEmber();


public:
	void UseMove(CPokemon* pokemon) override;
};

