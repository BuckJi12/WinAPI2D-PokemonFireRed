#include "framework.h"
#include "CMeetingTile.h"

CMeetingTile::CMeetingTile()
{
	m_pImage = nullptr;
	m_pAnimator = nullptr;
	m_time = 0.f;
	m_vecScale = Vector(64, 64);
	m_vecPos = Vector(64, 64);
	m_layer = Layer::Environment;
}

CMeetingTile::~CMeetingTile()
{
}

void CMeetingTile::Init()
{
	m_pImage = RESOURCE->LoadImg(L"Grass", L"Image\\GrassTile.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Splash", m_pImage, Vector(0, 0), Vector(128.f, 128.f), Vector(128.f, 0.f), 0.5, 1);

	AddComponent(m_pAnimator);
	CTile::Init();

	AddCollider(ColliderType::Rect,
		Vector(CTile::TILESIZE, CTile::TILESIZE),
		Vector(CTile::TILESIZE / 2, CTile::TILESIZE / 2));
}

void CMeetingTile::Update()
{
	CTile::Update();
}

void CMeetingTile::Render()
{
	CTile::Render();

	ComponentRender();
}

void CMeetingTile::Release()
{
	CTile::Release();
}

void CMeetingTile::OnCollisionEnter(CCollider* pOther)
{
}

void CMeetingTile::OnCollisionStay(CCollider* pOther)
{
	m_pAnimator->Play(L"Splash", false);
	m_time += DT;
	if (GAME->canMeet && m_time > GAME->randomValue)
	{
		//TODO: 배틀씬 전환
		Logger::Debug(L"포켓몬 만났다");
		m_time = 0;
	}
}

void CMeetingTile::OnCollisionExit(CCollider* pOther)
{
	m_pAnimator->Stop();
}
