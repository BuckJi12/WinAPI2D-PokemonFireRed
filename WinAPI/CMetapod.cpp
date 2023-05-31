#include "framework.h"
#include "CMetapod.h"

CMetapod::CMetapod()
{
	// 포켓몬 정보
	m_info.name					= L"단데기";
	m_info.description			= L"";
	m_info.number				= 11;
	m_info.rate					= 120;
	m_info.evolutionNumber		= 12;

	// 포켓몬 기초값 파이리: 205
	m_baseStat.hp				= 50;
	m_baseStat.attack			= 20;
	m_baseStat.specialAttack	= 55;
	m_baseStat.defence			= 25;
	m_baseStat.specialDefence	= 25;
	m_baseStat.speed			= 30;

	m_curState					= PokemonState::Normal;
	m_owner						= PokemonOwner::Wild;
	m_type1						= PokemonType::Bug;
	m_type2						= PokemonType::None;
	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	Init();
}

CMetapod::~CMetapod()
{
}

CMetapod::CMetapod(const CMetapod& metapod) : CPokemon(metapod)
{
}

void CMetapod::Evolution()
{
}

void CMetapod::LearnMoveList()
{
}

void CMetapod::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CMetapod::Update()
{
	CPokemon::Update();
}

void CMetapod::Render()
{
	CPokemon::Render();
}

void CMetapod::Release()
{
	CPokemon::Release();
}
