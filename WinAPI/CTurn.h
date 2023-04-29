#pragma once

#include "CSceneBattle.h"
class CSceneBattle;

class CTurn
{
public:
	CTurn(CSceneBattle* battleScene);
	virtual ~CTurn();

protected:
	CSceneBattle* m_battleScene;

public:
	virtual void Init() = 0;
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;
	virtual void Release() = 0;
};

