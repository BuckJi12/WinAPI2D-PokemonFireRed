#include "framework.h"
#include "CCharizard.h"

CCharizard::CCharizard()
{
	// 포켓몬 정보
	m_info.name					= L"리자몽";
	m_info.description			= L"";
	m_info.number				= 6;
	m_info.rate					= 45;
	m_info.evolutionNumber		= -1;

	// 포켓몬 기초값 리자드: 534
	m_baseStat.hp				= 78;
	m_baseStat.attack			= 84;
	m_baseStat.specialAttack	= 78;
	m_baseStat.defence			= 109;
	m_baseStat.specialDefence	= 85;
	m_baseStat.speed			= 100;

	m_curState					= PokemonState::Normal;
	m_owner						= PokemonOwner::Wild;
	m_type1						= PokemonType::Fire;
	m_type2						= PokemonType::None;
	// 초기화
	m_pResource					= nullptr;
	m_pAnimator					= nullptr;

	m_fireBlast					= new CFireBlast;
	m_firePunch					= new CFirePunch;
	m_thunderPunch				= new CThunderPunch;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
}

CCharizard::~CCharizard()
{
}

CCharizard::CCharizard(const CCharizard& charizard) : CPokemon(charizard)
{
	m_fireBlast			= new CFireBlast;
	m_firePunch			= new CFirePunch;
	m_thunderPunch		= new CThunderPunch;
}

void CCharizard::Evolution()
{
}

void CCharizard::LearnMoveList()
{
	if (m_stat.level >= 17 && !m_firePunch->GetIsLearned())
	{
		LearnMove(m_firePunch);
		m_firePunch->SetLearned(true);
	}

	if (m_stat.level >= 27 && !m_thunderPunch->GetIsLearned())
	{
		LearnMove(m_thunderPunch);
		m_thunderPunch->SetLearned(true);
	}

	if (m_stat.level >= 35 && !m_fireBlast->GetIsLearned())
	{
		LearnMove(m_fireBlast);
		m_fireBlast->SetLearned(true);
	}
}

void CCharizard::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CCharizard::Update()
{
	CPokemon::Update();
}

void CCharizard::Render()
{
	CPokemon::Render();
}

void CCharizard::Release()
{
	CPokemon::Release();
}
