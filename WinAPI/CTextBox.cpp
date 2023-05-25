#include "framework.h"
#include "CTextBox.h"

CTextBox::CTextBox()
{
	m_text = L"";
}

CTextBox::~CTextBox()
{
}

void CTextBox::SetText(wstring text)
{
	m_text = text;
}

void CTextBox::Reset()
{
	m_text = L"";
}

void CTextBox::Init()
{
	SetImage(RESOURCE->LoadImg(L"TextBox", L"Image\\Battle\\TextBox.png"));
}

void CTextBox::Update()
{
}

void CTextBox::Render()
{
	CImageObject::Render();

	RENDER->Text(
		m_text,
		m_vecPos.x + 50,
		m_vecPos.y + 50,
		m_vecPos.x + 750,
		m_vecPos.y + 100,
		Color(255, 255, 255, 1),
		35
	);
}

void CTextBox::Release()
{
}
