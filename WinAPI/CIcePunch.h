#pragma once

class CIcePunch : public CMove
{
public:
	CIcePunch();
	virtual ~CIcePunch();


public:
	void UseMove(CPokemon* pokemon) override;
};

