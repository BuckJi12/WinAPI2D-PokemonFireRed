#include "framework.h"
#include "CEffectFire.h"

CEffectFire::CEffectFire()
{
	m_pAnimator = nullptr;
}

CEffectFire::~CEffectFire()
{
}

void CEffectFire::Init()
{
	m_pImage = RESOURCE->LoadImg(L"FireEffect", L"Image\\Effect\\FireEffect.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"EffectPlay", m_pImage, Vector(0, 0), Vector(128.f, 128.f), Vector(128.f, 0.f), 0.2, 3);
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
