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

	PokemonInfo operator= (const PokemonInfo& info)
	{
		name		= info.name;
		description = info.description;
		number		= info.number;
		rate		= info.rate;
		
		return *this;
	}
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
		maxHp			+= other.maxHp;
		curHp			+= other.curHp;	
		attack			+= other.attack;
		specialAttack	+= other.specialAttack;
		defence			+= other.defence;
		specialDefence	+= other.specialDefence;
		speed			+= other.speed;

		return *this;
	}

	PokemonStat operator-=(const PokemonStat& other)
	{
		maxHp			-= other.maxHp;
		curHp			-= other.curHp;
		attack			-= other.attack;
		specialAttack	-= other.specialAttack;
		defence			-= other.defence;
		specialDefence	-= other.specialDefence;
		speed			-= other.speed;

		return *this;
	}

	PokemonStat operator=(const PokemonStat& other)
	{
		level			= other.level;
		maxHp			= other.maxHp;
		curHp			= other.curHp;
		attack			= other.attack;
		specialAttack	= other.specialAttack;
		defence			= other.defence;
		specialDefence	= other.specialDefence;
		speed			= other.speed;
		curExp			= other.curExp;
		maxExp			= other.maxExp;

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

	PokemonBaseStat operator=(const PokemonBaseStat& baseStat)
	{
		hp				= baseStat.hp;
		attack			= baseStat.attack;
		specialAttack	= baseStat.specialAttack;
		defence			= baseStat.defence;
		specialDefence	= baseStat.specialDefence;
		speed			= baseStat.speed;

		return *this;
	}
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

	CPokemon(const CPokemon& pokemon);
	
private:
	list<IObserver*>	m_listObservers;
	Vector				m_originalLocation;
	Vector				m_knockBackLocation;
	float				m_timer;
	bool				m_onHit;

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
	vector<CMove*>		m_vecMoves;

public:
	PokemonInfo			GetPokemonInfo();
	PokemonStat			GetPokemonStat();
	PokemonStat			GetLevelStat(int level);
	PokemonState		GetCurState();
	PokemonType			GetType(int num);
	CPokemonResource*	GetPokemonResource();
	vector<CMove*>		GetPokemonMoveList();
	void				SetPokemonStat(int level);
	void				ChangeState(PokemonState state);
	void				AddExp(float exp);
	void				LevelUp();
	void				LearnMove(CMove* move);
	void				SetAnimation();
	void				TakeDamage(int value);
	void				HitAnimation();
	void				SetOwner(PokemonOwner owner);
	void				Recover();

public:
	virtual void		Evolution() {};
	virtual void		LearnMoveList() {};

	void				Init() override;
protected:
	void				Update() override;
	void				Render() override;
	void				Release() override;

public:
	void				AddObserver(IObserver* observer) override;
	void				RemoveObserver(IObserver* observer) override;
	void				Notify() override;
};

