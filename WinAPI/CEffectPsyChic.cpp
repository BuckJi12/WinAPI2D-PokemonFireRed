#include "framework.h"
#include "CEffectPsyChic.h"

CEffectPsyChic::CEffectPsyChic()
{
	m_pAnimator = nullptr;
	m_layer		= Layer::Environment3;
}

CEffectPsyChic::~CEffectPsyChic()
{
}

void CEffectPsyChic::Init()
{
	m_pImage = RESOURCE->LoadImg(L"PsychicEffect", L"Image\\Effect\\PsychicEffect.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"EffectPlay", m_pImage, Vector(0, 0), Vector(256.f, 256.f), Vector(256.f, 0.f), 0.2, 4, false);
	AddComponent(m_pAnimator);
}

void CEffectPsyChic::Update()
{
}

void CEffectPsyChic::Render()
{
}

void CEffectPsyChic::Release()
{
}
