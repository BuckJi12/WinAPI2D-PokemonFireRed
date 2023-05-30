#pragma once

class CCore;
class CMove;
class CItem;

enum class MoveResult
{
	Normal,
	Good,
	Bad,
	Nothing,

	Size
};

class CBattleManager : public SingleTon<CBattleManager>
{
	friend SingleTon<CBattleManager>;
	friend CCore;
private:
	CBattleManager();
	virtual ~CBattleManager();

private:
	CPokemon*		m_pPlayerCurPokemon;
	CPokemon*		m_pOppoentCurPokemon;
	CMove*			m_pOpponentCurMove;
	PlayerAction	m_curAction;
	FirstAttack		m_curFirstAttack;
	BattleSituation m_curBattleSituation;
	BattleResult	m_battleResult;
	MoveResult		m_curMoveResult;
	int				m_playerCurInex;

	int				m_catchRate;
	bool			m_isCatching;

public:
	CPokemon*		GetPlayerCurPokemon();
	CPokemon*		GetOpponentCurPokemon();
	PlayerAction	GetCurAction();
	FirstAttack		GetFirstAttack();
	BattleSituation GetBattleSituation();
	BattleResult	GetBattleResult();
	MoveResult		GetMoveResult();
	CMove*			GetCurMove();
	CMove*			GetCurOpponentMove();
	void			OpponentSelectMove();
	void			SetBattleResult(BattleResult result);
	void			SetFirstAttack(FirstAttack attack);
	void			SetBattleSituation(BattleSituation situation);
	void			BattleInit();	// 배틀 기본 설정
	void			ChooseAction(PlayerAction action); // 1. 배틀 2. 교체 3. 아이템 4. 도망
	void			CheckFirstAttack();
	void			PlayerAttack();
	void			OppoentUseMove();
	void			SelectMove(int index);
	void			CheckBattleAble();
	void			PokemonChanage(CPokemon* pokemon);

	int				CalculateDamage(CPokemon* attacker, CPokemon* victim, CMove* move);
	int				CalculateCatchRate(CItem* item);	//TODO: 아이템 추가
	bool			PlayerCheckBattleAble();
	void			IsGoodEffect(CPokemon* attacker, CPokemon* victim, CMove* move);
	
	CatchResult		TryPokemonCatch();
};

#define BATTLE CBattleManager::GetInstance()