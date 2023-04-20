#pragma once

struct MoveStats // 기술 스텟
{
	wstring		name;
	wstring		description;
	PokemonType moveType;
	MoveKind	moveKind;
	int			maxPP;
	int			curPP;
	int			moveDamage;
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

protected:
	MoveStats m_moveStat;

public:
	virtual void UseMove() = 0;
	void RecoverPP(int value);
};

