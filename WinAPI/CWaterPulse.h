#pragma once

class CWaterPulse: public CMove
{
public:
	CWaterPulse();
	virtual ~CWaterPulse();

public:
	void UseMove(CPokemon* pokemon) override;
};

