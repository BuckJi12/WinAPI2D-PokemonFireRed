#pragma once

class CHyperBeam : public CMove
{
public:
	CHyperBeam();
	virtual ~CHyperBeam();

public:
	void UseMove(CPokemon* pokemon) override;
};

