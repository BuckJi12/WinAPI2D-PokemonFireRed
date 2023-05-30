#pragma once

class CIceBeam : public CMove
{
public:
	CIceBeam();
	virtual ~CIceBeam();


public:
	void UseMove(CPokemon* pokemon) override;
};

