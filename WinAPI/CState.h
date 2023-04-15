#pragma once
#include "CPlayer.h"

class CPlayer;

class CState
{
public:
	CState(CPlayer* pPlayer);
	virtual ~CState();

protected:
	CPlayer* pPlayer;

public:
	virtual void Init() = 0;
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;
};

