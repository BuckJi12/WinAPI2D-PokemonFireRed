#pragma once
#include "CTurn.h"

class CTurnChooseAction : public CTurn
{
public:
	CTurnChooseAction(CSceneBattle* battleScene);
	virtual ~CTurnChooseAction();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

