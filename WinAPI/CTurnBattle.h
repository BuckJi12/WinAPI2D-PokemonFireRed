#pragma once
#include "CTurn.h"

class CTurnBattle : public CTurn
{
public:
	CTurnBattle(CSceneBattle* battleScene);
	virtual ~CTurnBattle();

private:
	float m_timer;

	bool m_playerAttacked;
	bool m_OpponentAttacked;

private:
	void PokemonAttack();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

