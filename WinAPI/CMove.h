#pragma once

struct MoveStats // ��� ����
{
	wstring		name;
	wstring		description;
	PokemonType moveType;
	MoveKind	moveKind;
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

public:
	virtual void UseMove() = 0;
	void RecoverPP(int value);
};

