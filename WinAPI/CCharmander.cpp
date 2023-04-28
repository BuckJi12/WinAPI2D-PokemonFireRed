#include "framework.h"
#include "CCharmander.h"


CCharmander::CCharmander(int level) : CPokemon(level)
{
	// 포켓몬 정보
	m_info.name = L"파이리";
	m_info.description = L"태어날 때부터 꼬리의 불꽃이 타오르고 있다.\n 불꽃이 꺼지면 그 생명이 다하고 만다.";
	m_info.number = 4;
	m_info.rate = 45;

	// 포켓몬 기초값 파이리: 309
	m_baseStat.hp = 39;
	m_baseStat.attack = 52;
	m_baseStat.specialAttack = 43;
	m_baseStat.defence = 60;
	m_baseStat.specialDefence = 50;
	m_baseStat.speed = 65;

	// 포켓몬 스텟
	SetPokemonStat(level);

	m_curState = PokemonState::Normal;
	m_owner = PokemonOwner::Wild;

	// 기본 기술
	// TODO: 기술 추가

	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	Init();
}

CCharmander::~CCharmander()
{
}

void CCharmander::Evolution()
{
	// TODO: 진화 구현
}

void CCharmander::LearnMoveList()
{
	// TODO: 배울 기술 정리
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
