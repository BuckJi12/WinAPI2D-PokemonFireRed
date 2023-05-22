#pragma once
#include "CImageObject.h"

class CItem : public CImageObject
{
public:
	CItem();
	virtual ~CItem();

public:
	wstring		m_name;
	wstring		m_description;

	int			m_count;
	int			m_cost;
	float		m_rate;

public:
	virtual void UseItem() {};

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

