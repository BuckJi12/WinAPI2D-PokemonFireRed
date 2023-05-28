#include "framework.h"
#include "CEffectWater.h"

CEffectWater::CEffectWater()
{
	m_pAnimator = nullptr;
	m_layer = Layer::Environment3;
}

CEffectWater::~CEffectWater()
{
}

void CEffectWater::Init()
{
	m_pImage = RESOURCE->LoadImg(L"WaterEffect", L"Image\\Effect\\WaterEffect.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"EffectPlay", m_pImage, Vector(0, 0), Vector(256.f, 256.f), Vector(256.f, 0.f), 0.2, 4, false);
	AddComponent(m_pAnimator);
}

void CEffectWater::Update()
{
}

void CEffectWater::Render()
{
}

void CEffectWater::Release()
{
}
