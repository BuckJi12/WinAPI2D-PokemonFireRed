#include "framework.h"
#include "CMoltres.h"

CMoltres::CMoltres()
{
	// 포켓몬 정보
	m_info.name						= L"파이어";
	m_info.description				= L"";
	m_info.number					= 19;
	m_info.rate						= 3;
	m_info.evolutionNumber			= -1;

	// 포켓몬 기초값 파이어: 580
	m_baseStat.hp					= 90;
	m_baseStat.attack				= 100;
	m_baseStat.specialAttack		= 90;
	m_baseStat.defence				= 125;
	m_baseStat.specialDefence		= 85;
	m_baseStat.speed				= 90;

	m_curState						= PokemonState::Normal;
	m_owner							= PokemonOwner::Wild;
	m_type1							= PokemonType::Fire;
	m_type2							= PokemonType::Flying;
	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	CMove* fireBlast = new CFireBlast;
	LearnMove(fireBlast);

	Init();
}

CMoltres::~CMoltres()
{
}

CMoltres::CMoltres(const CMoltres& moltres) : CPokemon(moltres)
{
}

CMoltres* CMoltres::Clone()
{
	CMoltres* copy = new CMoltres;
	copy->CPokemon::Clone();

	return copy;
}

void CMoltres::Evolution()
{
}

void CMoltres::LearnMoveList()
{
}

void CMoltres::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CMoltres::Update()
{
	CPokemon::Update();
}

void CMoltres::Render()
{
	CPokemon::Render();
}

void CMoltres::Release()
{
	CPokemon::Release();
}
