#pragma once
#include "CTurn.h"

class CTurnCatch : public CTurn
{
public:
	CTurnCatch(CSceneBattle* battleScene);
	virtual ~CTurnCatch();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

