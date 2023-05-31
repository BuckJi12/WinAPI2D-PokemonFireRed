#pragma once

class CEffectLightning : public CEffect
{
public:
	CEffectLightning();
	virtual ~CEffectLightning();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

