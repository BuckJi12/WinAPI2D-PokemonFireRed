#include "framework.h"
#include "CMeetingTile.h"

CMeetingTile::CMeetingTile()
{
	m_pImage = nullptr;
	m_pAnimator = nullptr;
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
	if (GAME->GetCanMeet())
		GAME->m_meetTime += 1;
	if (GAME->GetCanMeet() && GAME->m_meetTime > GAME->GetValue())
	{
		srand(time(NULL));
		int random = rand() % 18 + 1;
		int random2 = rand() % 10 - 5;
		int pokemonLevel = PLAYER->GetPlayerFirstPokemon()->GetPokemonStat().level - random2;
		BATTLE->BattleInit(random, pokemonLevel);
		CAMERA->FadeOut(0.25f);
		GAME->SetCanMove(false);
		DELAYCHANGESCENE(GroupScene::Battle, 0.5f);
	}
}

void CMeetingTile::OnCollisionStay(CCollider* pOther)
{
	m_pAnimator->Play(L"Splash", false);
	//if (GAME->m_canMeet && GAME->m_meetTime > GAME->m_randomValue)
	//{
	//	//TODO: ¹èÆ²¾À ÀüÈ¯
	//	CAMERA->FadeOut(0.25f);
	//	DELAYCHANGESCENE(GroupScene::Battle, 0.5f);
	//}
}

void CMeetingTile::OnCollisionExit(CCollider* pOther)
{
	m_pAnimator->Stop();
}
