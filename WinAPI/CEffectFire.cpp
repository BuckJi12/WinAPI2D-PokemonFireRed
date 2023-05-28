#include "framework.h"
#include "CEffectFire.h"

CEffectFire::CEffectFire()
{
	m_pAnimator = nullptr;
	m_layer = Layer::Environment3;
}

CEffectFire::~CEffectFire()
{
}

void CEffectFire::Init()
{
	m_pImage = RESOURCE->LoadImg(L"FireEffect", L"Image\\Effect\\FireEffect.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"EffectPlay", m_pImage, Vector(0, 0), Vector(256.f, 256.f), Vector(256.f, 0.f), 0.2, 4, false);
	AddComponent(m_pAnimator);
}

void CEffectFire::Update()
{
}

void CEffectFire::Render()
{
}

void CEffectFire::Release()
{
}
