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
	void BattleInit();	// ��Ʋ �⺻ ����
	void ChooseAction(PlayerAction action); // 1. ��Ʋ 2. ��ü 3. ������ 4. ����
	void CheckFirstAttack();
	void PlayerUseMove(int value);
	void OppoentUseMove();
	int	 CalculateDamage(CPokemon* attacker, CPokemon* victim, CMove move);
	int	 CalculateCatchRate();	//TODO: ������ �߰�
	void PokemonChanage(int index);
	bool TryPokemonCatch();
	bool CheckBattleAble();
};

