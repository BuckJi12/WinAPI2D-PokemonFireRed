#pragma once
#include "CPokemon.h"

class CCharmander : public CPokemon
{
public:
	CCharmander(int level);
	virtual ~CCharmander();

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

