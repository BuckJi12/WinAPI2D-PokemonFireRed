#pragma once
struct ItemData
{
	wstring		name;
	wstring		description;
	int			count;
	int			cost;
	float		rate;
};

class CItem
{
public:
	CItem();
	virtual ~CItem();

protected:
	CImage*			m_pImage;
	ItemData		m_itemData;

public:
	CImage*			GetImage();
	ItemData		GetItemData();
	void			SetCount(int count);
	void			UseItem();

public:
	virtual void	Init();
};

