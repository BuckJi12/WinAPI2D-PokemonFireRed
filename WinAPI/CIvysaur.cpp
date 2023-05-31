#include "framework.h"
#include "CIvysaur.h"

CIvysaur::CIvysaur()
{
	// 포켓몬 정보
	m_info.name					= L"이상해풀";
	m_info.description			= L"";
	m_info.number				= 2;
	m_info.rate					= 45;

	// 포켓몬 기초값 이상해풀: 405
	m_baseStat.hp				= 60;
	m_baseStat.attack			= 62;
	m_baseStat.specialAttack	= 63;
	m_baseStat.defence			= 80;
	m_baseStat.specialDefence	= 80;
	m_baseStat.speed			= 60;

	m_curState					= PokemonState::Normal;
	m_owner						= PokemonOwner::Wild;
	m_type1						= PokemonType::Grass;
	m_type2						= PokemonType::Poison;
	// 초기화
	m_pResource					= nullptr;
	m_pAnimator					= nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	m_vineWhip = new CVineWhip;
	Init();
}

CIvysaur::~CIvysaur()
{
}

CIvysaur::CIvysaur(const CIvysaur& ivysaur) : CPokemon(ivysaur)
{
	m_vineWhip = new CVineWhip;
}

void CIvysaur::Evolution()
{
}

void CIvysaur::LearnMoveList()
{
	if (m_stat.level >= 8 && !m_vineWhip->GetIsLearned())
	{
		LearnMove(m_vineWhip);
		m_vineWhip->SetLearned(true);
	}
}

void CIvysaur::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CIvysaur::Update()
{
	CPokemon::Update();
}

void CIvysaur::Render()
{
	CPokemon::Render();
}

void CIvysaur::Release()
{
	CPokemon::Release();
}
