#pragma once

class CTackle : public CMove
{
public:
	CTackle();
	virtual ~CTackle();

	
public:
	void UseMove(CPokemon* pokemon) override;
};

