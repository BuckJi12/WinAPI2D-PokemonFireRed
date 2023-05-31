#pragma once

class CEffectIce : public CEffect
{
public:
	CEffectIce();
	virtual ~CEffectIce();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

