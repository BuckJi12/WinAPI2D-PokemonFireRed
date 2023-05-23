#pragma once
#include "CImageObject.h"
#include "CItem.h"

class CBagWindow : public CImageObject
{
public:
	CBagWindow();
	virtual ~CBagWindow();

private:
	CImage* m_pItemIcon;
	wstring m_itemDescription;

public:
	CImage* GetItemIcon();
	void	SetItem(CItem item);

public:
	void	Init()		override;
	void	Update()	override;
	void	Render()	override;
	void	Release()	override;
};

