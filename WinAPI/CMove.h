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
	void			RecoverPP(int value);
	virtual void	UseMove(CPokemon* pokemon);
};

