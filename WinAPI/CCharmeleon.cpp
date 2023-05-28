#include "framework.h"
#include "CCharmeleon.h"

CCharmeleon::CCharmeleon()
{
	// 포켓몬 정보
	m_info.name					= L"리자드";
	m_info.description			= L"꼬리를 휘둘러 상대를 쓰러트리고 날카로운 발톱으로 갈기갈기 찢어버린다.";
	m_info.number				= 5;
	m_info.rate					= 45;
	m_info.evolutionNumber		= 6;

	// 포켓몬 기초값 리자드: 405
	m_baseStat.hp				= 58;
	m_baseStat.attack			= 64;
	m_baseStat.specialAttack	= 58;
	m_baseStat.defence			= 80;
	m_baseStat.specialDefence	= 65;
	m_baseStat.speed			= 80;

	m_curState					= PokemonState::Normal;
	m_owner						= PokemonOwner::Wild;
	m_type1						= PokemonType::Fire;
	m_type2						= PokemonType::None;
	// 초기화
	m_pResource					= nullptr;
	m_pAnimator					= nullptr;
	m_ember						= nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	m_ember = new CEmber;
	Init();
}

CCharmeleon::~CCharmeleon()
{
}

CCharmeleon::CCharmeleon(const CCharmeleon& charmeleon) : CPokemon(charmeleon)
{
	m_ember = new CEmber;
}

void CCharmeleon::Evolution()
{
	// TODO: 진화 구현
}

void CCharmeleon::LearnMoveList()
{
	// 배울 기술 정리
}

void CCharmeleon::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CCharmeleon::Update()
{
	CPokemon::Update();
}

void CCharmeleon::Render()
{
	CPokemon::Render();
}

void CCharmeleon::Release()
{
	CPokemon::Release();
}
