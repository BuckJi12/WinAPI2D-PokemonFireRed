#pragma once

class CThunderPunch : public CMove
{
public:
	CThunderPunch();
	virtual ~CThunderPunch();


public:
	void UseMove(CPokemon* pokemon) override;
};

