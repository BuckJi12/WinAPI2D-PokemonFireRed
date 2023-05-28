#pragma once
#include "CEffect.h"

class CEffectFire : public CEffect
{
public:
	CEffectFire();
	virtual ~CEffectFire();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

