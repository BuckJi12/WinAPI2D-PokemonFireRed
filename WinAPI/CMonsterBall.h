#pragma once
#include "CItem.h"

class CMonsterBall : public CItem
{
public:
	CMonsterBall();
	virtual ~CMonsterBall();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

