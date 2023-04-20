#include "framework.h"
#include "CPokemonResource.h"

CPokemonResource::CPokemonResource()
{
	m_pImage = nullptr;
	m_pIcon = nullptr;
}

CPokemonResource::~CPokemonResource()
{
}

CImage* CPokemonResource::GetImage()
{
	return m_pImage;
}

CImage* CPokemonResource::GetIcon()
{
	return m_pIcon;
}

void CPokemonResource::SetImage(CImage* image)
{
	m_pImage = image;
}

void CPokemonResource::SetIcon(CImage* icon)
{
	m_pIcon = icon;
}
