#include "framework.h"
#include "CPokemon.h"

#include "CMove.h"

#include "IObserver.h"

CPokemon::CPokemon(int level)
{
	m_stat.level = level;
}

CPokemon::~CPokemon()
{
}

PokemonInfo CPokemon::GetPokemonInfo()
{
	return m_info;
}

PokemonStat CPokemon::GetPokemonStat()
{
	return m_stat;
}

PokemonState CPokemon::GetCurState()
{
	return m_curState;
}

void CPokemon::SetPokemonStat(int level)
{
	m_stat.maxHp = (((m_baseStat.hp * 2) * ((float)level / 100)) + 10 + m_stat.level);
	m_stat.curHp = (((m_baseStat.hp * 2) * ((float)level / 100)) + 10 + m_stat.level);
	m_stat.attack = ((m_baseStat.attack * 2) * ((float)level / 100) + 5);
	m_stat.specialAttack = ((m_baseStat.specialAttack * 2) * ((float)level / 100) + 5);
	m_stat.defence = ((m_baseStat.defence * 2) * ((float)level / 100) + 5);
	m_stat.specialDefence = ((m_baseStat.specialDefence * 2) * ((float)level / 100) + 5);
	m_stat.speed = ((m_baseStat.speed * 2) * ((float)level / 100) + 5);
	Notify();
}

void CPokemon::ChangeState(PokemonState state)
{
	m_curState = state;

	switch (m_curState)
	{
	case PokemonState::Normal:
		break;
	case PokemonState::Paralysis:
		m_stat.speed = m_stat.speed / 2;
		break;
	case PokemonState::Faint:
		break;
	case PokemonState::Size:
		break;
	default:
		break;
	}
	Notify();
}

void CPokemon::AddExp(float exp)
{
	if (m_stat.level < 100)
	{
		m_stat.curExp += exp;
		if (m_stat.curExp >= m_stat.maxExp)
		{
			LevelUp();
		}
	}
	Notify();
}

void CPokemon::LevelUp()
{
	float temp = m_stat.curExp -= m_stat.maxExp;
	m_stat.curExp = 0;
	m_stat.level += 1;
	m_stat.curExp += temp;
	m_stat.maxExp = m_stat.maxExp * 1.2f;
	// TODO: 레벨업 시 스텟 증가 구현
	Notify();
}

void CPokemon::LearnMove(CMove* move)
{
	if (m_vecMoves.size() < 4)
	{
		m_vecMoves.push_back(*move);
	}
	Notify();
}

void CPokemon::TakeDamage(int value)
{
	m_stat.curHp -= value;
	if (m_stat.curHp <= 0)
	{
		m_stat.curHp = 0;
		ChangeState(PokemonState::Faint);
	}
	Notify();
}

void CPokemon::Recover()
{
	ChangeState(PokemonState::Faint);
	SetPokemonStat(m_stat.level);
	Notify();
}

void CPokemon::Init()
{
}

void CPokemon::Update()
{
}

void CPokemon::Render()
{
}

void CPokemon::Release()
{
}

void CPokemon::AddObserver(IObserver* observer)
{
	m_listObservers.push_back(observer);
}

void CPokemon::RemoveObserver(IObserver* observer)
{
	m_listObservers.remove(observer);
}

void CPokemon::Notify()
{
	auto iter = m_listObservers.begin();
	while (iter != m_listObservers.end())
	{
		(*iter)->Update();
	}
}
