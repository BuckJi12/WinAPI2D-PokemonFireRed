#include "framework.h"
#include "CZapdos.h"

CZapdos::CZapdos()
{
	// ���ϸ� ����
	m_info.name						= L"���";
	m_info.description				= L"";
	m_info.number					= 18;
	m_info.rate						= 3;
	m_info.evolutionNumber			= -1;

	// ���ϸ� ���ʰ� ���: 580
	m_baseStat.hp					= 90;
	m_baseStat.attack				= 90;
	m_baseStat.specialAttack		= 85;
	m_baseStat.defence				= 125;
	m_baseStat.specialDefence		= 90;
	m_baseStat.speed				= 100;

	m_curState						= PokemonState::Normal;
	m_owner							= PokemonOwner::Wild;
	m_type1							= PokemonType::Electric;
	m_type2							= PokemonType::Flying;
	// �ʱ�ȭ
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	Init();
}

CZapdos::~CZapdos()
{
}

CZapdos::CZapdos(const CZapdos& zapdos) : CPokemon(zapdos)
{
}

void CZapdos::Evolution()
{
}

void CZapdos::LearnMoveList()
{
}

void CZapdos::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CZapdos::Update()
{
	CPokemon::Update();
}

void CZapdos::Render()
{
	CPokemon::Render();
}

void CZapdos::Release()
{
	CPokemon::Release();
}
