#include "framework.h"
#include "CPokemon.h"

#include "CMove.h"

#include "IObserver.h"

CPokemon::CPokemon(int level)
{
	m_stat.level = level;

	// 포켓몬 정보
	m_info.name = L"";
	m_info.description = L"";
	m_info.number = 0;
	m_info.rate = 255;

	// 포켓몬 기초값 파이리: 309
	m_baseStat.hp = 1;
	m_baseStat.attack = 1;
	m_baseStat.specialAttack = 1;
	m_baseStat.defence = 1;
	m_baseStat.specialDefence = 1;
	m_baseStat.speed = 1;

	// 포켓몬 스텟
	SetPokemonStat(level);

	m_curState = PokemonState::Normal;
	m_owner = PokemonOwner::Wild;

	// 기본 기술
	// TODO: 기술 추가

	// 초기화
	m_pResource = nullptr;
	m_pAnimator = nullptr;
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

PokemonStat CPokemon::GetLevelStat(int level)
{
	PokemonStat temp {};
	temp.maxHp = (int)(((m_baseStat.hp * 2) * ((float)level / 100)) + 10 + m_stat.level);
	temp.curHp = (int)(((m_baseStat.hp * 2) * ((float)level / 100)) + 10 + m_stat.level);
	temp.attack = (int)((m_baseStat.attack * 2) * ((float)level / 100) + 5);
	temp.specialAttack = (int)((m_baseStat.specialAttack * 2) * ((float)level / 100) + 5);
	temp.defence = (int)((m_baseStat.defence * 2) * ((float)level / 100) + 5);
	temp.specialDefence = (int)((m_baseStat.specialDefence * 2) * ((float)level / 100) + 5);
	temp.speed = (int)((m_baseStat.speed * 2) * ((float)level / 100) + 5);
	return temp;
}

PokemonState CPokemon::GetCurState()
{
	return m_curState;
}

CPokemonResource* CPokemon::GetPokemonResource()
{
	return m_pResource;
}

vector<CMove> CPokemon::GetPokemonMoveList()
{
	return m_vecMoves;
}

void CPokemon::SetPokemonStat(int level)
{
	m_stat.maxHp = (int)(((m_baseStat.hp * 2) * ((float)level / 100)) + 10 + m_stat.level);
	m_stat.curHp = (int)(((m_baseStat.hp * 2) * ((float)level / 100)) + 10 + m_stat.level);
	m_stat.attack = (int)((m_baseStat.attack * 2) * ((float)level / 100) + 5);
	m_stat.specialAttack = (int)((m_baseStat.specialAttack * 2) * ((float)level / 100) + 5);
	m_stat.defence = (int)((m_baseStat.defence * 2) * ((float)level / 100) + 5);
	m_stat.specialDefence = (int)((m_baseStat.specialDefence * 2) * ((float)level / 100) + 5);
	m_stat.speed = (int)((m_baseStat.speed * 2) * ((float)level / 100) + 5);
	m_stat.maxExp = 500 * ((float)level / 100);
	m_pSubject->Notify();
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
	m_pSubject->Notify();
}

void CPokemon::AddExp(float exp)
{
	bool canLevelUp = true;
	if (m_stat.level < 100)
	{
		while (canLevelUp)
		{
			m_stat.curExp += exp;
			canLevelUp = false;
			if (m_stat.curExp >= m_stat.maxExp)
			{
				LevelUp();
				canLevelUp = true;
			}
		}
	}
	m_pSubject->Notify();
}

void CPokemon::LevelUp()
{
	float temp = m_stat.curExp -= m_stat.maxExp;
	m_stat.curExp = 0;
	m_stat.level += 1;
	m_stat.curExp += temp;
	m_stat.maxExp += 500;
	PokemonStat increaseValue;
	increaseValue = (GetLevelStat(m_stat.level) -= GetLevelStat(m_stat.level - 1));
	m_stat += increaseValue;
	m_pSubject->Notify();
}

void CPokemon::LearnMove(CMove* move)
{
	if (m_vecMoves.size() < 4)
	{
		m_vecMoves.push_back(*move);
	}
	m_pSubject->Notify();
}

void CPokemon::TakeDamage(int value)
{
	m_stat.curHp -= value;
	if (m_stat.curHp <= 0)
	{
		m_stat.curHp = 0;
		ChangeState(PokemonState::Faint);
	}
	m_pSubject->Notify();
}

void CPokemon::Recover()
{
	ChangeState(PokemonState::Normal);
	SetPokemonStat(m_stat.level);
	m_pSubject->Notify();
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
	m_pSubject->AddObserver(observer);
}

void CPokemon::RemoveObserver(IObserver* observer)
{
	m_pSubject->RemoveObserver(observer);
}
