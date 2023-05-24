#pragma once
#include "CTurn.h"

class CBallObject;

class CTurnCatch : public CTurn
{
public:
	CTurnCatch(CSceneBattle* battleScene);
	virtual ~CTurnCatch();

private:
	CBallObject*	m_pBallObject;
	CatchResult		m_catchResult;

	float			m_timer;
	bool			m_pokemonMoved;
	bool			m_catchComplete;

private:
	void Setting();
	void PokemonReset();
	void CatchFail();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

