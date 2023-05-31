#include "framework.h"
#include "CCaterpie.h"

CCaterpie::CCaterpie()
{
	// 포켓몬 정보
	m_info.name							= L"캐터피";
	m_info.description					= L"";
	m_info.number						= 10;
	m_info.rate							= 255;
	m_info.evolutionNumber				= 11;

	// 포켓몬 기초값 캐터피: 195
	m_baseStat.hp						= 45;
	m_baseStat.attack					= 30;
	m_baseStat.specialAttack			= 35;
	m_baseStat.defence					= 20;
	m_baseStat.specialDefence			= 20;
	m_baseStat.speed					= 45;

	m_curState							= PokemonState::Normal;
	m_owner								= PokemonOwner::Wild;
	m_type1								= PokemonType::Bug;
	m_type2								= PokemonType::None;
	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	Init();
}

CCaterpie::~CCaterpie()
{
}

CCaterpie::CCaterpie(const CCaterpie& caterpie) : CPokemon(caterpie)
{
}

void CCaterpie::Evolution()
{
}

void CCaterpie::LearnMoveList()
{
}

void CCaterpie::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CCaterpie::Update()
{
	CPokemon::Update();
}

void CCaterpie::Render()
{
	CPokemon::Render();
}

void CCaterpie::Release()
{
	CPokemon::Release();
}
