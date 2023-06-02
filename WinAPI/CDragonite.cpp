#include "framework.h"
#include "CDragonite.h"

CDragonite::CDragonite()
{
	// Æ÷ÄÏ¸ó Á¤º¸
	m_info.name					= L"¸Á³ª´¨";
	m_info.description			= L"";
	m_info.number				= 16;
	m_info.rate					= 45;
	m_info.evolutionNumber		= -1;

	// Æ÷ÄÏ¸ó ±âÃÊ°ª ¸Á³ª´¨: 600
	m_baseStat.hp				= 91;
	m_baseStat.attack			= 134;
	m_baseStat.specialAttack	= 95;
	m_baseStat.defence			= 100;
	m_baseStat.specialDefence	= 100;
	m_baseStat.speed			= 80;

	m_curState					= PokemonState::Normal;
	m_owner						= PokemonOwner::Wild;
	m_type1						= PokemonType::Dragon;
	m_type2						= PokemonType::Flying;
	// ÃÊ±âÈ­
	m_pResource = nullptr;
	m_pAnimator = nullptr;


	CMove* tackle = new CTackle;
	LearnMove(tackle);
	CMove* thunderPunch = new CThunderPunch;
	LearnMove(thunderPunch);
	CMove* icePunch = new CIcePunch;
	LearnMove(icePunch);
	CMove* firePunch = new CFirePunch;
	LearnMove(firePunch);

	Init();
}

CDragonite::~CDragonite()
{
}

CDragonite::CDragonite(const CDragonite& dragonite) : CPokemon(dragonite)
{
}

CDragonite* CDragonite::Clone()
{
	CDragonite* copy = new CDragonite;
	copy->CPokemon::Clone();

	return copy;
}

void CDragonite::Evolution()
{
}

void CDragonite::LearnMoveList()
{
}

void CDragonite::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CDragonite::Update()
{
	CPokemon::Update();
}

void CDragonite::Render()
{
	CPokemon::Render();
}

void CDragonite::Release()
{
	CPokemon::Release();
}
