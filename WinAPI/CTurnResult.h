#pragma once
#include "CTurn.h"

class CTurnResult : public CTurn
{
public:
	CTurnResult(CSceneBattle* battleScene);
	virtual ~CTurnResult();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

