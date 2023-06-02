#pragma once
#include "CPokemon.h"

class CCharmander : public CPokemon
{
public:
	CCharmander();
	virtual ~CCharmander();

	CCharmander(const CCharmander& charmander);
	CCharmander* Clone() override;

private:
	CMove* m_ember;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

