#include "framework.h"
#include "CEffectNormal.h"

CEffectNormal::CEffectNormal()
{
	m_pAnimator = nullptr;
	m_layer = Layer::Environment3;
}

CEffectNormal::~CEffectNormal()
{
}

void CEffectNormal::Init()
{
	m_pImage = RESOURCE->LoadImg(L"NormalEffect", L"Image\\Effect\\NormalEffect.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"EffectPlay", m_pImage, Vector(0, 0), Vector(256.f, 256.f), Vector(256.f, 0.f), 0.2, 4, false);
	AddComponent(m_pAnimator);
}

void CEffectNormal::Update()
{
}

void CEffectNormal::Render()
{
}

void CEffectNormal::Release()
{
}
