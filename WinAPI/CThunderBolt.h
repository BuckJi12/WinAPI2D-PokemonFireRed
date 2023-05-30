#pragma once

class CThunderBolt : public CMove
{
public:
	CThunderBolt();
	virtual ~CThunderBolt();


public:
	void UseMove(CPokemon* pokemon) override;
};

