#pragma once

struct MoveStats // ��� ����
{
	wstring		name;
	wstring		description;
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
	virtual void UseMove() {};
	void RecoverPP(int value);
};

