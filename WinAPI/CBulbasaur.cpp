#include "framework.h"
#include "CBulbasaur.h"

CBulbasaur::CBulbasaur()
{
	// ���ϸ� ����
	m_info.name					= L"�̻��ؾ�";
	m_info.description			= L"";
	m_info.number				= 1;
	m_info.rate					= 45;

	// ���ϸ� ���ʰ� �̻��ؾ�: 318
	m_baseStat.hp				= 45;
	m_baseStat.attack			= 49;
	m_baseStat.specialAttack	= 49;
	m_baseStat.defence			= 65;
	m_baseStat.specialDefence	= 65;
	m_baseStat.speed			= 45;

	m_curState					= PokemonState::Normal;
	m_owner						= PokemonOwner::Wild;
	m_type1						= PokemonType::Grass;
	m_type2						= PokemonType::Poison;

	// �⺻ ���
	// TODO: ��� �߰�

	// �ʱ�ȭ
	m_pResource					= nullptr;
	m_pAnimator					= nullptr;

	CTackle* tackle = new CTackle;
	LearnMove(tackle);
	Init();
}

CBulbasaur::~CBulbasaur()
{
}

void CBulbasaur::Evolution()
{
	// TODO: ��ȭ ����
}

void CBulbasaur::LearnMoveList()
{
	// TODO: ��� ��� ����
}

void CBulbasaur::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CBulbasaur::Update()
{
	CPokemon::Update();
}

void CBulbasaur::Render()
{
}

void CBulbasaur::Release()
{
	delete m_pResource;
}
