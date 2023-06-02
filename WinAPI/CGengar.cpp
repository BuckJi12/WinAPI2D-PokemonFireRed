#include "framework.h"
#include "CGengar.h"

CGengar::CGengar()
{
	// 포켓몬 정보
	m_info.name						= L"팬텀";
	m_info.description				= L"";
	m_info.number					= 14;
	m_info.rate						= 45;
	m_info.evolutionNumber			= -1;

	// 포켓몬 기초값 파이리: 500
	m_baseStat.hp					= 60;
	m_baseStat.attack				= 65;
	m_baseStat.specialAttack		= 60;
	m_baseStat.defence				= 130;
	m_baseStat.specialDefence		= 75;
	m_baseStat.speed				= 110;

	m_curState						= PokemonState::Normal;
	m_owner							= PokemonOwner::Wild;
	m_type1							= PokemonType::Ghost;
	m_type2							= PokemonType::Poison;
	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;


	CMove* tackle = new CTackle;
	LearnMove(tackle);
	CMove* psychic = new CPsychic;
	LearnMove(psychic);
	CMove* fireBlast = new CFireBlast;
	LearnMove(fireBlast);
	CMove* icePunch = new CIcePunch;
	LearnMove(icePunch);

	Init();
}

CGengar::~CGengar()
{
}

CGengar::CGengar(const CGengar& gengar) : CPokemon(gengar)
{
}

CGengar* CGengar::Clone()
{
	CGengar* copy = new CGengar;
	copy->CPokemon::Clone();

	return copy;
}

void CGengar::Evolution()
{
}

void CGengar::LearnMoveList()
{
}

void CGengar::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CGengar::Update()
{
	CPokemon::Update();
}

void CGengar::Render()
{
	CPokemon::Render();
}

void CGengar::Release()
{
	CPokemon::Release();
}
