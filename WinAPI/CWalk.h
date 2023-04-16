#pragma once
#include "CState.h"

class CWalk : public CState
{
public:
	CWalk(CPlayer* player);
	virtual ~CWalk();

private:
	CImage* m_pWalkImage;
	float m_speed;

public:
	virtual void Init() override;
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

