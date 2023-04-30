#pragma once
#include "CTurn.h"

class CBallObject;

class CTurnPlayerReady : public CTurn
{
public:
	CTurnPlayerReady(CSceneBattle* battleScene);
	virtual ~CTurnPlayerReady();

private:
	float m_time;
	CBallObject* m_pBallObject;

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

