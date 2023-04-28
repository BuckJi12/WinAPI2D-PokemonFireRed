#include "framework.h"
#include "CCharmander.h"


CCharmander::CCharmander(int level) : CPokemon(level)
{
	// ���ϸ� ����
	m_info.name = L"���̸�";
	m_info.description = L"�¾ ������ ������ �Ҳ��� Ÿ������ �ִ�.\n �Ҳ��� ������ �� ������ ���ϰ� ����.";
	m_info.number = 4;
	m_info.rate = 45;

	// ���ϸ� ���ʰ� ���̸�: 309
	m_baseStat.hp = 39;
	m_baseStat.attack = 52;
	m_baseStat.specialAttack = 43;
	m_baseStat.defence = 60;
	m_baseStat.specialDefence = 50;
	m_baseStat.speed = 65;

	// ���ϸ� ����
	SetPokemonStat(level);

	m_curState = PokemonState::Normal;
	m_owner = PokemonOwner::Wild;

	// �⺻ ���
	// TODO: ��� �߰�

	// �ʱ�ȭ
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	Init();
}

CCharmander::~CCharmander()
{
}

void CCharmander::Evolution()
{
	// TODO: ��ȭ ����
}

void CCharmander::LearnMoveList()
{
	// TODO: ��� ��� ����
}

void CCharmander::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CCharmander::Update()
{
}

void CCharmander::Render()
{
}

void CCharmander::Release()
{
	delete m_pResource;
	delete m_pAnimator;
}
