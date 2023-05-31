#include "framework.h"
#include "CEffectIce.h"

CEffectIce::CEffectIce()
{
	m_pAnimator = nullptr;
	m_layer		= Layer::Environment3;
}

CEffectIce::~CEffectIce()
{
}

void CEffectIce::Init()
{
	m_pImage = RESOURCE->LoadImg(L"IceEffect", L"Image\\Effect\\IceEffect.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"EffectPlay", m_pImage, Vector(0, 0), Vector(256.f, 256.f), Vector(256.f, 0.f), 0.2, 4, false);
	AddComponent(m_pAnimator);
}

void CEffectIce::Update()
{
}

void CEffectIce::Render()
{
}

void CEffectIce::Release()
{
}
