#pragma once

class CSelectBox : public CGameObject
{
public:
	CSelectBox();
	virtual ~CSelectBox();

private:
	Vector	m_vecBoxSize;
	Color	m_boxColor;
	float	m_strokeWidth;

public:
	void SetSize(float xSize, float ySize, float strokeWidth = 0);
	void SetColor(BYTE r = 0, BYTE g = 0, BYTE b = 0);

public:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

