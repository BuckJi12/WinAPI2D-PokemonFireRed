#pragma once

class CEffectPsyChic : public CEffect
{
public:
	CEffectPsyChic();
	virtual ~CEffectPsyChic();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

