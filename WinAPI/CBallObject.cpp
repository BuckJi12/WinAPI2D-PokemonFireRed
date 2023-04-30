#include "framework.h"
#include "CBallObject.h"

CBallObject::CBallObject()
{
	m_targetPos = Vector(0, 0);
	m_difValue = Vector(0, 0);
	m_curMode = BallMode::None;

	m_pAnimator = nullptr;
	
	m_isDown = false;
	m_isStop = false;
	Init();
}

CBallObject::~CBallObject()
{
}

void CBallObject::BallMove()
{
	switch (m_curMode)
	{
	case BallMode::None:
		break;
	case BallMode::TakeOut:
		if (m_vecPos.y < 200)
			m_isDown = true;

		if (!m_isDown)
		{
			m_vecPos.x += 100 * DT;
			m_vecPos.y -= 150 * DT;
		}
		else
		{
			m_vecPos.x += 50 * DT;
			m_vecPos.y += 150 * DT;
		}
		break;
	case BallMode::Catch:
		if (m_vecPos.y < 100)
			m_isDown = true;
		if (m_vecPos.x > m_targetPos.x)
		{
			m_isStop = true;
			m_curMode = BallMode::CollsionTarget;
			m_pAnimator->Play(L"OpenClose");
		}

		if (!m_isDown)
		{
			m_vecPos.x += 250 * DT;
			m_vecPos.y -= 200 * DT;
		}

		if (!m_isStop && m_isDown)
		{
			m_vecPos.x += (m_difValue.x) * DT;
			m_vecPos.y += (m_difValue.y * 2) * DT;
		}
		break;
	case BallMode::CollsionTarget:
		if (m_vecPos.y < 225)
		{
			m_vecPos.y += 50 * DT;
		}
		
		if (m_vecPos.y > 225)
		{
			m_curMode = BallMode::Catching;
			m_pAnimator->Play(L"Catching");
		}
	case BallMode::Catching:
	default:
		break;
	}
}

void CBallObject::SetMode(BallMode mode)
{
	m_curMode = mode;
}

void CBallObject::SetBall()
{
	//TODO: 볼 추가시 볼에 따른 이미지 변경
}

void CBallObject::SetAnimation(const wstring& aniName)
{
	m_pAnimator->Play(aniName);
}

void CBallObject::SetTarget(CGameObject* object)
{
	m_targetPos = object->m_vecPos;
	m_difValue.x = object->m_vecPos.x - 400;
	m_difValue.y = object->m_vecPos.y - 125;
}

void CBallObject::Init()
{
	m_pImage = RESOURCE->LoadImg(L"MonsterBall", L"Image\\Battle\\MonsterBall.png");
	
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Spin", m_pImage, Vector(0, 0), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.1, 4);
	m_pAnimator->CreateAnimation(L"OpenClose", m_pImage, Vector(0, 64), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.5, 5, false);
	m_pAnimator->CreateAnimation(L"Catching", m_pImage, Vector(0, 128), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.3, 5);
	m_pAnimator->CreateAnimation(L"Stop", m_pImage, Vector(0, 128), Vector(64.f, 64.f), Vector(64.f, 0.f), 0.3, 1);
	AddComponent(m_pAnimator);
	m_pAnimator->Play(L"Spin");
}

void CBallObject::Update()
{
	BallMove();
}

void CBallObject::Render()
{
}

void CBallObject::Release()
{
}
