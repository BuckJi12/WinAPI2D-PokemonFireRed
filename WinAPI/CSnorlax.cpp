#include "framework.h"
#include "CSnorlax.h"

CSnorlax::CSnorlax()
{
	// 포켓몬 정보
	m_info.name					= L"잠만보";
	m_info.description			= L"";
	m_info.number				= 15;
	m_info.rate					= 25;
	m_info.evolutionNumber		= -1;

	// 포켓몬 기초값 잠만보: 540
	m_baseStat.hp				= 160;
	m_baseStat.attack			= 110;
	m_baseStat.specialAttack	= 65;
	m_baseStat.defence			= 65;
	m_baseStat.specialDefence	= 110;
	m_baseStat.speed			= 30;

	m_curState					= PokemonState::Normal;
	m_owner						= PokemonOwner::Wild;
	m_type1						= PokemonType::Normal;
	m_type2						= PokemonType::None;
	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	CMove* icePunch = new CIcePunch;
	LearnMove(icePunch);
	CMove* hyperBeam = new CHyperBeam;
	LearnMove(hyperBeam);
	Init();
}

CSnorlax::~CSnorlax()
{
}

CSnorlax::CSnorlax(const CSnorlax& snorlax) : CPokemon(snorlax)
{
}

CSnorlax* CSnorlax::Clone()
{
	CSnorlax* copy = new CSnorlax;
	copy->CPokemon::Clone();

	return copy;
}

void CSnorlax::Evolution()
{
}

void CSnorlax::LearnMoveList()
{
}

void CSnorlax::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CSnorlax::Update()
{
	CPokemon::Update();
}

void CSnorlax::Render()
{
	CPokemon::Render();
}

void CSnorlax::Release()
{
	CPokemon::Release();
}
