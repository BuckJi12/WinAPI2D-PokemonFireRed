#include "framework.h"
#include "CPikachu.h"

CPikachu::CPikachu()
{
	// 포켓몬 정보
	m_info.name						= L"피카츄";
	m_info.description				= L"";
	m_info.number					= 13;
	m_info.rate						= 85;
	m_info.evolutionNumber			= -1;

	// 포켓몬 기초값 피카츄 원래 320 여긴 500
	m_baseStat.hp					= 85;
	m_baseStat.attack				= 65;
	m_baseStat.specialAttack		= 110;
	m_baseStat.defence				= 60;
	m_baseStat.specialDefence		= 60;
	m_baseStat.speed				= 120;

	m_curState						= PokemonState::Normal;
	m_owner							= PokemonOwner::Wild;
	m_type1							= PokemonType::Electric;
	m_type2							= PokemonType::None;
	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	CMove* thunderBolt = new CThunderBolt;
	LearnMove(thunderBolt);
	CMove* thunderPunch = new CThunderPunch;
	LearnMove(thunderPunch);
	Init();
}

CPikachu::~CPikachu()
{
}

CPikachu::CPikachu(const CPikachu& pikachu) : CPokemon(pikachu)
{
}

CPikachu* CPikachu::Clone()
{
	CPikachu* copy = new CPikachu;
	copy->CPokemon::Clone();

	return copy;
}

void CPikachu::Evolution()
{
}

void CPikachu::LearnMoveList()
{
}

void CPikachu::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CPikachu::Update()
{
	CPokemon::Update();
}

void CPikachu::Render()
{
	CPokemon::Render();
}

void CPikachu::Release()
{
	CPokemon::Release();
}
