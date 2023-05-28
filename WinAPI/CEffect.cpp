#include "framework.h"
#include "CEffect.h"

CEffect::CEffect()
{
	m_pAnimator = nullptr;
}

CEffect::~CEffect()
{
}

void CEffect::Play()
{
	m_pAnimator->Play(L"EffectPlay", true);
}

void CEffect::Init()
{
}

void CEffect::Update()
{
}

void CEffect::Render()
{
}

void CEffect::Release()
{
}
