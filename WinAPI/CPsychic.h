#pragma once

class CPsychic : public CMove
{
public:
	CPsychic();
	virtual ~CPsychic();


public:
	void UseMove(CPokemon* pokemon) override;
};

