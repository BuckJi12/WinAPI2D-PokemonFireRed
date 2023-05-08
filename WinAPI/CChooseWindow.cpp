#include "framework.h"
#include "CChooseWindow.h"

#include "CImageObject.h"

CChooseWindow::CChooseWindow()
{
	m_layer = Layer::Environment3;
}

CChooseWindow::~CChooseWindow()
{
}

void CChooseWindow::Init()
{
	m_pImage = RESOURCE->LoadImg(L"ChooseWindow", L"Image\\Battle\\ChooseWindow.png");
}

void CChooseWindow::Update()
{
}

void CChooseWindow::Render()
{
	CImageObject::Render();

	/*RENDER->Text(
		L"�ο��",
		m_vecPos.x + 40,
		m_vecPos.y + 25,
		m_vecPos.x + 180,
		m_vecPos.y + 50,
		Color(0, 0, 0, 1),
		25
	);

	RENDER->Text(
		L"����",
		m_vecPos.x + 240,
		m_vecPos.y + 225,
		m_vecPos.x + 320,
		m_vecPos.y + 50,
		Color(0, 0, 0, 1),
		25
	);

	RENDER->Text(
		L"���ϸ�",
		m_vecPos.x + 40,
		m_vecPos.y + 60,
		m_vecPos.x + 180,
		m_vecPos.y + 80,
		Color(0, 0, 0, 1),
		25
	);

	RENDER->Text(
		L"��������",
		m_vecPos.x + 240,
		m_vecPos.y + 260,
		m_vecPos.x + 320,
		m_vecPos.y + 80,
		Color(0, 0, 0, 1),
		25
	);*/
}

void CChooseWindow::Release()
{
}