#pragma once

class CCore;

class CBattleManager : public SingleTon<CBattleManager>
{
	friend SingleTon<CBattleManager>;
	friend CCore;
private:
	CBattleManager();
	virtual ~CBattleManager();

private:
	CPokemon* m_pPlayerCurPokemon;
	CPokemon* m_pOppoentCurPokemon;
	PlayerAction m_curAction;
	FirstAttack m_curFirstAttack;

	int catchRate;
	bool isCatching;

public:
	void BattleInit();	// 배틀 기본 설정
	void ChooseAction(PlayerAction action); // 1. 배틀 2. 교체 3. 아이템 4. 도망
	void CheckFirstAttack();
	void PlayerUseMove(int value);
	void OppoentUseMove();
	int	 CalculateDamage(CPokemon* attacker, CPokemon* victim, CMove move);
	int	 CalculateCatchRate();	//TODO: 아이템 추가
	void PokemonChanage(int index);
	bool TryPokemonCatch();
	bool CheckBattleAble();
};

