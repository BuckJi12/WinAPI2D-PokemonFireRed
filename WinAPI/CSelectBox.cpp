#include "framework.h"
#include "CSelectBox.h"

CSelectBox::CSelectBox()
{
	m_layer			= Layer::Environment;
	m_vecBoxSize	= Vector(10, 10);
	m_boxColor		= Color(0, 0, 0, 1);
	m_strokeWidth	= 1;
}

CSelectBox::~CSelectBox()
{
}

void CSelectBox::SetSize(float xSize, float ySize, float strokeWidth)
{
	m_vecBoxSize	= Vector(xSize, ySize);
	m_strokeWidth	= strokeWidth;
}

void CSelectBox::SetColor(BYTE r, BYTE g, BYTE b)
{
	m_boxColor		= Color(r, g, b, 1);
}

void CSelectBox::Init()
{
}

void CSelectBox::Update()
{
}

void CSelectBox::Render()
{
	RENDER->FrameRect(
		m_vecPos.x,
		m_vecPos.y,
		m_vecPos.x + m_vecBoxSize.x,
		m_vecPos.y + m_vecBoxSize.y,
		m_boxColor,
		m_strokeWidth
	);
}

void CSelectBox::Release()
{
}
