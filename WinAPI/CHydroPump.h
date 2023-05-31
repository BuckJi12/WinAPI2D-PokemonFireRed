#pragma once

class CHydroPump : public CMove
{
public:
	CHydroPump();
	virtual ~CHydroPump();

public:
	void UseMove(CPokemon* pokemon) override;
};

