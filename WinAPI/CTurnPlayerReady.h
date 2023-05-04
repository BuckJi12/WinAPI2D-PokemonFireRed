#pragma once
#include "CTurn.h"

class CBallObject;
class CPlayerStatUI;

class CTurnPlayerReady : public CTurn
{
public:
	CTurnPlayerReady(CSceneBattle* battleScene);
	virtual ~CTurnPlayerReady();

private:
	CBallObject*	m_pBallObject;
	CPlayerStatUI*	m_pImagePlayerStatUI;
	float			m_time;

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

