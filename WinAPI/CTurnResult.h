#pragma once
#include "CTurn.h"

class CTurnResult : public CTurn
{
public:
	CTurnResult(CSceneBattle* battleScene);
	virtual ~CTurnResult();

private:

	float	m_timer;
	bool	m_gotReward;

private:
	void GetReward();
	void BattleLose();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

