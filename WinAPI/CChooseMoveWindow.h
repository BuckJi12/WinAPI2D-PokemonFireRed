#pragma once
#include "CImageObject.h"

class CChooseMoveWindow : public CImageObject
{
public:
	CChooseMoveWindow();
	virtual ~CChooseMoveWindow();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

