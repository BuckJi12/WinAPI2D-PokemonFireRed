#pragma once
class CPokemonResource;
class IObserver;
class CMove;
class CSubject;

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

	PokemonStat operator+=(const PokemonStat& other)
	{
		maxHp += other.maxHp;
		curHp += other.curHp;	
		attack += other.attack;
		specialAttack += other.specialAttack;
		defence += other.defence;
		specialDefence += other.specialDefence;
		speed += other.speed;

		return *this;
	}

	PokemonStat operator-=(const PokemonStat& other)
	{
		maxHp -= other.maxHp;
		curHp -= other.curHp;
		attack -= other.attack;
		specialAttack -= other.specialAttack;
		defence -= other.defence;
		specialDefence -= other.specialDefence;
		speed -= other.speed;

		return *this;
	}
};

struct PokemonBaseStat	// 포켓몬 종족값 ex) 망나뇽 600족
{
	int		hp;
	int		attack;
	int		specialAttack;
	int		defence;
	int		specialDefence;
	int		speed;
};

enum class PokemonState	// 포켓몬 현재 상태 ex) 기절, 마비
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

class CPokemon : public CGameObject, public ISubject
{
public:
	CPokemon();
	virtual ~CPokemon();
	
private:
	list<IObserver*>		m_listObservers;

protected:
	PokemonInfo			m_info;
	PokemonStat			m_stat;
	PokemonBaseStat		m_baseStat;
	PokemonState		m_curState;
	PokemonType			m_type1;
	PokemonType			m_type2;
	PokemonOwner		m_owner;
	CPokemonResource*	m_pResource;
	CAnimator*			m_pAnimator;
	vector<CMove>		m_vecMoves;

public:
	PokemonInfo			GetPokemonInfo();
	PokemonStat			GetPokemonStat();
	PokemonStat			GetLevelStat(int level);
	PokemonState		GetCurState();
	PokemonType			GetType(int num);
	CPokemonResource*	GetPokemonResource();
	vector<CMove>		GetPokemonMoveList();
	void				SetPokemonStat(int level);
	void				ChangeState(PokemonState state);
	void				AddExp(float exp);
	void				LevelUp();
	void				LearnMove(CMove move);
	void				SetAnimation();
	void				TakeDamage(int value);
	void				SetOwner(PokemonOwner owner);
	void				Recover();

public:
	virtual void		Evolution() {};
	virtual void		LearnMoveList() {};

private:
	void				Init() override;
	void				Update() override;
	void				Render() override;
	void				Release() override;

public:
	void				AddObserver(IObserver* observer) override;
	void				RemoveObserver(IObserver* observer) override;
	void				Notify() override;
};

