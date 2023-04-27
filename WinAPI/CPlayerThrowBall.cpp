#include "framework.h"
#include "CPlayerThrowBall.h"

CPlayerThrowBall::CPlayerThrowBall()
{
	m_pImage = nullptr;
	m_pAnimator = nullptr;


	m_point = Vector(202, 335);
	isThrew = false;

	m_pImage = RESOURCE->LoadImg(L"PlayerThrow", L"Image\\Battle\\PlayerThrow.png");

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"Idle", m_pImage, Vector(0, 0), Vector(256.f, 256.f), Vector(256.f, 0.f), 0.5, 1);
	m_pAnimator->CreateAnimation(L"Throw", m_pImage, Vector(0, 0), Vector(256.f, 256.f), Vector(256.f, 0.f), 0.2, 5);

	AddComponent(m_pAnimator);
	m_pAnimator->Play(L"Idle");
}

CPlayerThrowBall::~CPlayerThrowBall()
{
}

void CPlayerThrowBall::Setting(Vector pos)
{
	m_vecPos = pos;
	isThrew = false;
	m_pAnimator->Play(L"Idle");
}

void CPlayerThrowBall::Play()
{
	m_pAnimator->Play(L"Throw");
	isThrew = true;
}

void CPlayerThrowBall::Init()
{
}

void CPlayerThrowBall::Update()
{
	if (m_vecPos.x > m_point.x && isThrew == false)
	{
		m_vecPos.x -= 1000 * DT;
	}

	if (m_vecPos.x > -200 && isThrew == true)
	{
		m_vecPos.x -= 300 * DT;
	}
}

void CPlayerThrowBall::Render()
{
}

void CPlayerThrowBall::Release()
{
}
