#pragma once

class CFirePunch : public CMove
{
public:
	CFirePunch();
	virtual ~CFirePunch();


public:
	void UseMove(CPokemon* pokemon) override;
};

