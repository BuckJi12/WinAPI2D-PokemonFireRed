#include "framework.h"
#include "CArticuno.h"

CArticuno::CArticuno()
{
	// 포켓몬 정보
	m_info.name						= L"파이리";
	m_info.description				= L"";
	m_info.number					= 17;
	m_info.rate						= 3;
	m_info.evolutionNumber			= -1;

	// 포켓몬 기초값 프리져: 580
	m_baseStat.hp					= 90;
	m_baseStat.attack				= 85;
	m_baseStat.specialAttack		= 100;
	m_baseStat.defence				= 95;
	m_baseStat.specialDefence		= 125;
	m_baseStat.speed				= 85;

	m_curState						= PokemonState::Normal;
	m_owner							= PokemonOwner::Wild;
	m_type1							= PokemonType::Ice;
	m_type2							= PokemonType::Flying;
	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	CMove* iceBeam = new CIceBeam;
	LearnMove(iceBeam);
	Init();
}

CArticuno::~CArticuno()
{
}

CArticuno::CArticuno(const CArticuno& articuno) : CPokemon(articuno)
{
}

void CArticuno::Evolution()
{
}

void CArticuno::LearnMoveList()
{
}

void CArticuno::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CArticuno::Update()
{
	CPokemon::Update();
}

void CArticuno::Render()
{
	CPokemon::Render();
}

void CArticuno::Release()
{
	CPokemon::Release();
}
