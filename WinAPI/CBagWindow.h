#pragma once
#include "CImageObject.h"

class CBagWindow : public CImageObject
{
public:
	CBagWindow();
	virtual ~CBagWindow();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

