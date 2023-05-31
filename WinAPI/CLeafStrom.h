#pragma once

class CLeafStrom : public CMove
{
public:
	CLeafStrom();
	virtual ~CLeafStrom();

public:
	void UseMove(CPokemon* pokemon) override;
};

