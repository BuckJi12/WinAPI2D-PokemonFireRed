#pragma once
#include "CImageObject.h"

class CChooseWindow : public CImageObject
{
public:
	CChooseWindow();
	virtual ~CChooseWindow();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

