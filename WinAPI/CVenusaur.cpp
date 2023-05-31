#include "framework.h"
#include "CVenusaur.h"

CVenusaur::CVenusaur()
{
	// 포켓몬 정보
	m_info.name						= L"이상해꽃";
	m_info.description				= L"";
	m_info.number					= 3;
	m_info.rate						= 45;

	// 포켓몬 기초값 이상해꽃: 525
	m_baseStat.hp					= 80;
	m_baseStat.attack				= 82;
	m_baseStat.specialAttack		= 83;
	m_baseStat.defence				= 100;
	m_baseStat.specialDefence		= 100;
	m_baseStat.speed				= 80;

	m_curState						= PokemonState::Normal;
	m_owner							= PokemonOwner::Wild;
	m_type1							= PokemonType::Grass;
	m_type2							= PokemonType::Poison;
	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	CMove* vineWhip = new CVineWhip;
	LearnMove(vineWhip);
	m_leafStorm = new CLeafStrom;
	Init();
}

CVenusaur::~CVenusaur()
{
}

CVenusaur::CVenusaur(const CVenusaur& venusaur) : CPokemon(venusaur)
{
	m_leafStorm = new CLeafStrom;
}

void CVenusaur::Evolution()
{
}

void CVenusaur::LearnMoveList()
{
	// 배울 기술 정리
	if (m_stat.level >= 24 && !m_leafStorm->GetIsLearned())
	{
		LearnMove(m_leafStorm);
		m_leafStorm->SetLearned(true);
	}
}

void CVenusaur::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CVenusaur::Update()
{
	CPokemon::Update();
}

void CVenusaur::Render()
{
	CPokemon::Render();
}

void CVenusaur::Release()
{
	CPokemon::Release();
}
