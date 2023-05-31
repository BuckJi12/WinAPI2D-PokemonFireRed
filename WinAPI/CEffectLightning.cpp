#include "framework.h"
#include "CEffectLightning.h"

CEffectLightning::CEffectLightning()
{
	m_pAnimator		= nullptr;
	m_layer			= Layer::Environment3;
}

CEffectLightning::~CEffectLightning()
{
}

void CEffectLightning::Init()
{
	m_pImage = RESOURCE->LoadImg(L"LightningEffect", L"Image\\Effect\\LightningEffect.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"EffectPlay", m_pImage, Vector(0, 0), Vector(256.f, 256.f), Vector(256.f, 0.f), 0.2, 4, false);
	AddComponent(m_pAnimator);
}

void CEffectLightning::Update()
{
}

void CEffectLightning::Render()
{
}

void CEffectLightning::Release()
{
}
