#pragma once

class CWaterGun : public CMove
{
public:
	CWaterGun();
	virtual ~CWaterGun();

public:
	void UseMove(CPokemon* pokemon) override;
};

