#include "framework.h"
#include "CMewtwo.h"

CMewtwo::CMewtwo()
{
	// 포켓몬 정보
	m_info.name					= L"뮤츠";
	m_info.description			= L"";
	m_info.number				= 20;
	m_info.rate					= 3;
	m_info.evolutionNumber		= -1;

	// 포켓몬 기초값 뮤추: 680
	m_baseStat.hp				= 106;
	m_baseStat.attack			= 110;
	m_baseStat.specialAttack	= 90;
	m_baseStat.defence			= 154;
	m_baseStat.specialDefence	= 90;
	m_baseStat.speed			= 130;

	m_curState					= PokemonState::Normal;
	m_owner						= PokemonOwner::Wild;
	m_type1						= PokemonType::Psychic;
	m_type2						= PokemonType::None;
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

CMewtwo::~CMewtwo()
{
}

CMewtwo::CMewtwo(const CMewtwo& mewtwo) : CPokemon(mewtwo)
{
}

CMewtwo* CMewtwo::Clone()
{
	CMewtwo* copy = new CMewtwo;
	copy->CPokemon::Clone();

	return copy;
}

void CMewtwo::Evolution()
{
}

void CMewtwo::LearnMoveList()
{
}

void CMewtwo::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CMewtwo::Update()
{
	CPokemon::Update();
}

void CMewtwo::Render()
{
	CPokemon::Render();
}

void CMewtwo::Release()
{
	CPokemon::Release();
}
