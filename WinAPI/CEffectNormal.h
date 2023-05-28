#pragma once

class CEffectNormal : public CEffect
{
public:
	CEffectNormal();
	virtual ~CEffectNormal();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

