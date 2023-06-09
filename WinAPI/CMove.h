#pragma once

struct MoveStats // 기술 스텟
{
	wstring		name;
	wstring		description;
	wstring		moveType;
	int			maxPP;
	int			curPP;
	int			moveDamage;

	MoveStats operator=(const MoveStats& stat)
	{
		name		= stat.name;
		description = stat.description;
		moveType	= stat.moveType;
		maxPP		= stat.maxPP;
		curPP		= stat.curPP;
		moveDamage	= stat.moveDamage;

		return *this;
	}
};

enum class MoveKind // 기술 종류
{
	Physics,	// 물리 기술
	Special,	// 특수 기술
	Change,		// 변화 기술

	Size
};

class CMove
{
public:
	CMove();
	virtual ~CMove();

	CMove(const CMove& move);

protected:
	MoveStats	m_moveStat;
	PokemonType m_moveType;
	MoveKind	m_moveKind;

	bool		m_isLearned;

public:
	MoveStats		GetMoveStat();
	PokemonType		GetType();
	MoveKind		GetKind();
	
	bool			GetIsLearned();
	void			SetLearned(bool isLearned);
	void			RecoverPP();
	virtual void	UseMove(CPokemon* pokemon);
};

