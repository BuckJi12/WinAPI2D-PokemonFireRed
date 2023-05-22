#include "framework.h"
#include "CBagWindow.h"

CBagWindow::CBagWindow()
{
	m_layer = Layer::Environment2;
}

CBagWindow::~CBagWindow()
{
}

void CBagWindow::Init()
{
	m_pImage = RESOURCE->LoadImg(L"BagWindow", L"Image\\Battle\\Bag_In_Battle.png");
}

void CBagWindow::Update()
{
}

void CBagWindow::Render()
{
}

void CBagWindow::Release()
{
}
