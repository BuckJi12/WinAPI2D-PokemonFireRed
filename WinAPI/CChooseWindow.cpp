#include "framework.h"
#include "CChooseWindow.h"

#include "CImageObject.h"

CChooseWindow::CChooseWindow()
{
	m_layer = Layer::Environment2;
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
}

void CChooseWindow::Release()
{
}