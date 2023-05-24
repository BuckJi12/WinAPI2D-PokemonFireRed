#pragma once
#include "CTurn.h"

class CBallObject;

class CTurnPlayerReady : public CTurn
{
public:
	CTurnPlayerReady(CSceneBattle* battleScene);
	virtual ~CTurnPlayerReady();

private:
	CBallObject*	m_pBallObject;
	float			m_time;

	bool			m_isUICreated;

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

