#include "framework.h"
#include "CEffectGrass.h"

CEffectGrass::CEffectGrass()
{
	m_pAnimator = nullptr;
	m_layer = Layer::Environment3;
}

CEffectGrass::~CEffectGrass()
{
}

void CEffectGrass::Init()
{
	m_pImage = RESOURCE->LoadImg(L"GrassEffect", L"Image\\Effect\\GrassEffect.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"EffectPlay", m_pImage, Vector(0, 0), Vector(256.f, 256.f), Vector(256.f, 0.f), 0.2, 4, false);
	AddComponent(m_pAnimator);
}

void CEffectGrass::Update()
{
}

void CEffectGrass::Render()
{
}

void CEffectGrass::Release()
{
}
