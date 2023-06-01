#pragma once
#include "CTurn.h"

class CTurnBattle : public CTurn
{
public:
	CTurnBattle(CSceneBattle* battleScene);
	virtual ~CTurnBattle();

private:
	float	m_timer;

	bool	m_playerAttacked;
	bool	m_OpponentAttacked;
	bool	m_checkPlayer;
	bool	m_checkOpponent;

private:
	void PokemonAttack();
	void OutPutMoveResult(MoveResult result);

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

