#pragma once

class CTackle : CMove
{
public:
	CTackle();
	virtual ~CTackle();

public:
	void UseMove(CPokemon* pokemon) override;
};

