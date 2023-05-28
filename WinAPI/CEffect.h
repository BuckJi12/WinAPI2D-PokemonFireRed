#pragma once
#include "CImageObject.h"

class CEffect : public CImageObject 
{
public:
	CEffect();
	virtual ~CEffect();

public:
	virtual void Play() {};

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

