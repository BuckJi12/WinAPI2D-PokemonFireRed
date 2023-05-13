#pragma once
#include "CTurn.h"

class CTurnBattle : public CTurn
{
public:
	CTurnBattle(CSceneBattle* battleScene);
	virtual ~CTurnBattle();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

