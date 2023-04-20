#pragma once
class CPokemonResource;
class IObserver;
class CMove;

struct PokemonInfo
{
	wstring name;
	wstring description;
	int		number;
	int		rate;
};

struct PokemonStat
{
	int		level;

	int		maxHp;
	int		curHp;
	int		attack;
	int		specialAttack;
	int		defence;
	int		specialDefence;
	int		speed;

	float	curExp;
	float	maxExp;
};

struct PokemonBaseStat	// ���ϸ� ������ ex) ������ 600��
{
	int		hp;
	int		attack;
	int		specialAttack;
	int		defence;
	int		specialDefence;
	int		speed;
};

enum class PokemonState	// ���ϸ� ���� ���� ex) ����, ����
{
	Normal,
	Paralysis,
	
	Faint,
	Size
};

enum class PokemonOwner
{
	Player,
	Trainer,
	Wild,

	Size,
};

class CPokemon : public CGameObject
{
public:
	CPokemon(int level);
	virtual ~CPokemon();
	
private:
	list<IObserver*>		m_listObservers;

protected:
	PokemonInfo			m_info;
	PokemonStat			m_stat;
	PokemonBaseStat		m_baseStat;
	PokemonState		m_curState;
	PokemonOwner		m_owner;
	CPokemonResource*	m_pResource;
	CAnimator*			m_pAnimator;
	vector<CMove>		m_vecMoves;

public:
	PokemonInfo			GetPokemonInfo();
	PokemonStat			GetPokemonStat();
	PokemonState		GetCurState();
	void				SetPokemonStat(int level);
	void				ChangeState(PokemonState state);
	void				AddExp(float exp);
	void				LevelUp();
	void				LearnMove(CMove* move);
	void				TakeDamage(int value);
	void				Recover();

public:
	virtual void		Evolution() = 0;
	virtual void		LearnMoveList() = 0;

private:
	void				Init() override;
	void				Update() override;
	void				Render() override;
	void				Release() override;

	void				AddObserver(IObserver* observer) override;
	void				RemoveObserver(IObserver* observer) override;
	void				Notify() override;
};
