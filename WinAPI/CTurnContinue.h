#pragma once
#include "CTurn.h"

class CTurnContinue : public CTurn
{
public:
	CTurnContinue(CSceneBattle* battleScene);
	virtual ~CTurnContinue();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

