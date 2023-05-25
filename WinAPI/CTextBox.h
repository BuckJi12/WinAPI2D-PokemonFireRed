#pragma once
#include "CImageObject.h"

class CTextBox : public CImageObject
{
public:
	CTextBox();
	virtual ~CTextBox();

private:
	wstring m_text;

public:
	void SetText(wstring text);
	void Reset();

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

