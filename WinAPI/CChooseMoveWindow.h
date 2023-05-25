#pragma once
#include "CImageObject.h"

class CChooseMoveWindow : public CImageObject
{
public:
	CChooseMoveWindow();
	virtual ~CChooseMoveWindow();

private:
	int	m_curCount;

public:
	void SetCount(int num);

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

