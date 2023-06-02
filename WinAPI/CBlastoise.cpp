#include "framework.h"
#include "CBlastoise.h"

CBlastoise::CBlastoise()
{
	// Æ÷ÄÏ¸ó Á¤º¸
	m_info.name						= L"°ÅºÏ¿Õ";
	m_info.description				= L"";
	m_info.number					= 9;
	m_info.rate						= 45;
	m_info.evolutionNumber			= -1;

	// Æ÷ÄÏ¸ó ±âÃÊ°ª °ÅºÏ¿Õ: 530
	m_baseStat.hp					= 79;
	m_baseStat.attack				= 83;
	m_baseStat.specialAttack		= 100;
	m_baseStat.defence				= 85;
	m_baseStat.specialDefence		= 105;
	m_baseStat.speed				= 78;

	m_curState						= PokemonState::Normal;
	m_owner							= PokemonOwner::Wild;
	m_type1							= PokemonType::Water;
	m_type2							= PokemonType::None;
	// ÃÊ±âÈ­
	m_pResource = nullptr;
	m_pAnimator = nullptr;

	CMove* tackle = new CTackle;
	LearnMove(tackle);
	CMove* waterPulse = new CWaterPulse;
	LearnMove(waterPulse);
	CMove* hyperBeam = new CHyperBeam;
	LearnMove(hyperBeam);
	m_hydroPump = new CHydroPump;
	Init();
}

CBlastoise::~CBlastoise()
{
}

CBlastoise::CBlastoise(const CBlastoise& blastoise)
{
	m_hydroPump = new CHydroPump;
}

CBlastoise* CBlastoise::Clone()
{
	CBlastoise* copy = new CBlastoise;
	copy->CPokemon::Clone();

	return copy;
}

void CBlastoise::Evolution()
{
}

void CBlastoise::LearnMoveList()
{
	if (m_stat.level >= 30 && !m_hydroPump->GetIsLearned())
	{
		LearnMove(m_hydroPump);
		m_hydroPump->SetLearned(true);
	}
}

void CBlastoise::Init()
{
	m_pResource = new CPokemonResource();
	m_pResource = RESOURCE->GetPokemonResource(m_info.number);

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Front", m_pResource->GetImage(), Vector(0, 0), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	m_pAnimator->CreateAnimation(L"Back", m_pResource->GetImage(), Vector(0, 256), Vector(256, 256), Vector(256, 0.f), 0.2, 1);
	AddComponent(m_pAnimator);
}

void CBlastoise::Update()
{
	CPokemon::Update();
}

void CBlastoise::Render()
{
	CPokemon::Render();
}

void CBlastoise::Release()
{
	CPokemon::Release();
}
