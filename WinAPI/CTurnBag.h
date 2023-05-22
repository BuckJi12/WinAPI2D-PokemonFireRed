#pragma once
#include "CTurn.h"

class CTurnBag : public CTurn
{
public:
	CTurnBag(CSceneBattle* battleScene);
	virtual ~CTurnBag();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

