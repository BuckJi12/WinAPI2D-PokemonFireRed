#pragma once
#include "CTurn.h"

class CTurnPlayerReady : public CTurn
{
public:
	CTurnPlayerReady(CSceneBattle* battleScene);
	virtual ~CTurnPlayerReady();

private:
	float m_time;

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

