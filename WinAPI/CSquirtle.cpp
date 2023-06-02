#include "framework.h"
#include "CSquirtle.h"

CSquirtle::CSquirtle()
{
	// ���ϸ� ����
	m_info.name					= L"���α�";
	m_info.description			= L"";
	m_info.number				= 7;
	m_info.rate					= 45;

	// ���ϸ� ���ʰ� ���α�: 314
	m_baseStat.hp				= 44;
	m_baseStat.attack			= 48;
	m_baseStat.specialAttack	= 65;
	m_baseStat.defence			= 50;
	m_baseStat.specialDefence	= 64;
	m_baseStat.speed			= 43;

	m_curState					= PokemonState::Normal;
	m_owner						= PokemonOwner::Wild;
	m_type1						= PokemonType::Water;
	m_type2						= PokemonType::None;
	// �ʱ�ȭ
	m_pResource					= nullptr;
	m_pAnimator					= nullptr;

	// �⺻ ���
	CTackle* tackle = new CTackle;
	LearnMove(tackle);
	Init();
}

CSquirtle::~CSquirtle()
{
}

CSquirtle::CSquirtle(const CSquirtle& squirtle) : CPokemon(squirtle)
{
}

CSquirtle* CSquirtle::Clone()
{
	CSquirtle* copy = new CSquirtle;
	copy->CPokemon::Clone();

	return copy;
}

void CSquirtle::Evolution()
{
	// TODO: ��ȭ ����
}

void CSquirtle::LearnMoveList()
{
	// TODO: ��� ��� ����
}

void CSquirtle::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CSquirtle::Update()
{
	CPokemon::Update();
}

void CSquirtle::Render()
{
}

void CSquirtle::Release()
{
	delete m_pResource;
}
