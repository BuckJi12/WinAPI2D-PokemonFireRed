#pragma once
#include "CTurn.h"

class CBagWindow;

class CTurnBag : public CTurn
{
public:
	CTurnBag(CSceneBattle* battleScene);
	virtual ~CTurnBag();

private:
	CBagWindow* m_pImageBagWindow;

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

