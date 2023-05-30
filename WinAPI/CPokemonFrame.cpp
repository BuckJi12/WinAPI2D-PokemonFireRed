#include "framework.h"
#include "CPokemonFrame.h"

CPokemonFrame::CPokemonFrame()
{
	m_layer = Layer::Interface;
	m_pImageFrame	= nullptr;
	m_pImagePokemon = nullptr;
}

CPokemonFrame::~CPokemonFrame()
{
}

void CPokemonFrame::SetImage(CImage* image)
{
	m_pImagePokemon = image;
}

void CPokemonFrame::Init()
{
	m_pImageFrame = RESOURCE->LoadImg(L"PokemonFrame" , L"Image\\UI\\PokemonFrame.png");
}

void CPokemonFrame::Update()
{
}

void CPokemonFrame::Render()
{
	if (m_pImageFrame != nullptr)
	{
		RENDER->Image(
			m_pImageFrame,
			m_vecPos.x - (float)m_pImageFrame->GetWidth() * 0.5f,
			m_vecPos.y - (float)m_pImageFrame->GetWidth() * 0.5f,
			m_vecPos.x + (float)m_pImageFrame->GetWidth() * 0.5f,
			m_vecPos.y + (float)m_pImageFrame->GetHeight() * 0.5f
		);
	}

	if (m_pImagePokemon != nullptr)
	{
		RENDER->Image(
			m_pImagePokemon,
			m_vecPos.x - (float)m_pImagePokemon->GetWidth() * 0.5f,
			m_vecPos.y - (float)m_pImagePokemon->GetHeight() * 0.5f + 20,
			m_vecPos.x + (float)m_pImagePokemon->GetWidth() * 0.5f,
			m_vecPos.y + (float)m_pImagePokemon->GetHeight() * 0.5f + 20
		);
	}
}

void CPokemonFrame::Release()
{
}
