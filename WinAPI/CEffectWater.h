#pragma once

class CEffectWater : public CEffect
{
public:
	CEffectWater();
	virtual ~CEffectWater();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

