#pragma once
#include "CState.h"

class CIdle : public CState
{
public:
	CIdle(CPlayer* player);
	virtual ~CIdle();

private:
	CImage* m_pIdleImage;

public:
	virtual void Init() override;
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

