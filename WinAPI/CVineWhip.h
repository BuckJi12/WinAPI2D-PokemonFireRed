#pragma once

class CVineWhip : public CMove
{
public:
	CVineWhip();
	virtual ~CVineWhip();

public:
	void UseMove(CPokemon* pokemon) override;
};

