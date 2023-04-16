#pragma once
#include "CState.h"

class CRun : public CState
{
public:
	CRun(CPlayer* player);
	virtual ~CRun();

private:
	CImage* m_pRunImage;
	float m_speed;

public:
	virtual void Init() override;
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

