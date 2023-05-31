#include "framework.h"
#include "CWartortle.h"

CWartortle::CWartortle()
{
	// ���ϸ� ����
	m_info.name						= L"��Ϻα�";
	m_info.description				= L"";
	m_info.number					= 8;
	m_info.rate						= 45;

	// ���ϸ� ���ʰ� ��Ϻα�: 405
	m_baseStat.hp					= 59;
	m_baseStat.attack				= 63;
	m_baseStat.specialAttack		= 80;
	m_baseStat.defence				= 65;
	m_baseStat.specialDefence		= 80;
	m_baseStat.speed				= 58;

	m_curState						= PokemonState::Normal;
	m_owner							= PokemonOwner::Wild;
	m_type1							= PokemonType::Water;
	m_type2							= PokemonType::None;
	// �ʱ�ȭ
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	CMove* waterGun = new CWaterGun;
	LearnMove(waterGun);
	CMove* waterPulse = new CWaterPulse;
	LearnMove(waterPulse);
	Init();
}

CWartortle::~CWartortle()
{
}

CWartortle::CWartortle(const CWartortle& wartortle) : CPokemon(wartortle)
{
}

void CWartortle::Evolution()
{
}

void CWartortle::LearnMoveList()
{
}

void CWartortle::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CWartortle::Update()
{
	CPokemon::Update();
}

void CWartortle::Render()
{
	CPokemon::Render();
}

void CWartortle::Release()
{
	CPokemon::Release();
}
