#pragma once
#include "CTurn.h"

class CTurnChange : public CTurn
{
public:
	CTurnChange(CSceneBattle* battleScene);
	virtual ~CTurnChange();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

