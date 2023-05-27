#pragma once
#include "CPokemon.h"

class CCharmander : public CPokemon
{
public:
	CCharmander();
	virtual ~CCharmander();

	CCharmander(const CCharmander& charmander);

private:
	CMove* m_ember;

public:
	void Evolution() override;
	void LearnMoveList() override;
	void Init() override;

private:
	void Update() override;
	void Render() override;
	void Release() override;
};

