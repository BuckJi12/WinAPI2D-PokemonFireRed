#pragma once

struct MoveStats // ��� ����
{
	wstring		name;
	wstring		description;
	wstring		moveType;
	int			maxPP;
	int			curPP;
	int			moveDamage;
};

enum class MoveKind // ��� ����
{
	Physics,	// ���� ���
	Special,	// Ư�� ���
	Change,		// ��ȭ ���

	Size
};

class CMove
{
public:
	CMove();
	virtual ~CMove();

protected:
	MoveStats m_moveStat;
	PokemonType m_moveType;
	MoveKind m_moveKind;

public:
	MoveStats GetMoveStat();
	PokemonType GetType();
	MoveKind GetKind();
	virtual void UseMove(CPokemon* pokemon);
	void RecoverPP(int value);
};

