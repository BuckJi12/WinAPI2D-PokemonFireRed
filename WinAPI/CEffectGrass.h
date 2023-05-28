#pragma once

class CEffectGrass : public CEffect
{
public:
	CEffectGrass();
	virtual ~CEffectGrass();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

