#include "framework.h"
#include "CButterfree.h"

CButterfree::CButterfree()
{
	// 포켓몬 정보
	m_info.name						= L"버터플";
	m_info.description				= L"";
	m_info.number					= 12;
	m_info.rate						= 45;
	m_info.evolutionNumber			= -1;

	// 포켓몬 기초값 버터플: 395
	m_baseStat.hp					= 60;
	m_baseStat.attack				= 45;
	m_baseStat.specialAttack		= 50;
	m_baseStat.defence				= 90;
	m_baseStat.specialDefence		= 80;
	m_baseStat.speed				= 70;

	m_curState						= PokemonState::Normal;
	m_owner							= PokemonOwner::Wild;
	m_type1							= PokemonType::Bug;
	m_type2							= PokemonType::Flying;
	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	Init();
}

CButterfree::~CButterfree()
{
}

CButterfree::CButterfree(const CButterfree& butterfree) : CPokemon(butterfree)
{
}

CButterfree* CButterfree::Clone()
{
	CButterfree* copy = new CButterfree;
	copy->CPokemon::Clone();

	return copy;
}

void CButterfree::Evolution()
{
}

void CButterfree::LearnMoveList()
{
}

void CButterfree::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CButterfree::Update()
{
	CPokemon::Update();
}

void CButterfree::Render()
{
	CPokemon::Render();
}

void CButterfree::Release()
{
	CPokemon::Release();
}
