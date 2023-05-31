#pragma once

class CFireBlast : public CMove
{
public:
	CFireBlast();
	virtual ~CFireBlast();


public:
	void UseMove(CPokemon* pokemon) override;
};

