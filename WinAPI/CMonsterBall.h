#pragma once
#include "CItem.h"

class CMonsterBall : public CItem
{
public:
	CMonsterBall();
	virtual ~CMonsterBall();

public:
	void Init()		override;
};

