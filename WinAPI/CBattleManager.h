#pragma once

class CCore;
class CMove;
class CItem;

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
	PlayerAction	m_curAction;
	FirstAttack		m_curFirstAttack;
	BattleSituation m_curBattleSituation;
	BattleResult	m_battleResult;
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
	void			SetBattleResult(BattleResult result);
	void			SetFirstAttack(FirstAttack attack);
	void			SetBattleSituation(BattleSituation situation);
	void			BattleInit();	// ��Ʋ �⺻ ����
	void			ChooseAction(PlayerAction action); // 1. ��Ʋ 2. ��ü 3. ������ 4. ����
	void			CheckFirstAttack();
	void			PlayerAttack();
	void			OppoentUseMove();
	void			SelectMove(int index);
	void			CheckBattleAble();
	void			PokemonChanage(CPokemon* pokemon);

	int				CalculateDamage(CPokemon* attacker, CPokemon* victim, CMove* move);
	int				CalculateCatchRate(CItem* item);	//TODO: ������ �߰�
	bool			PlayerCheckBattleAble();
	
	CatchResult		TryPokemonCatch();
};

#define BATTLE CBattleManager::GetInstance()