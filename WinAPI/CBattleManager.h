#pragma once

class CCore;
class CMove;

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
	int				m_playerCurInex;

	int catchRate;
	bool isCatching;

public:
	CPokemon*		GetPlayerCurPokemon();
	CPokemon*		GetOpponentCurPokemon();
	PlayerAction	GetCurAction();
	FirstAttack		GetFirstAttack();
	BattleSituation GetBattleSituation();
	void			BattleInit();	// ��Ʋ �⺻ ����
	void			ChooseAction(PlayerAction action); // 1. ��Ʋ 2. ��ü 3. ������ 4. ����
	void			CheckFirstAttack();
	void			PlayerAttack();
	void			OppoentUseMove();
	void			SelectMove(int index);
	void			CheckBattleAble();
	void			PokemonChanage(CPokemon* pokemon);

	int				CalculateDamage(CPokemon* attacker, CPokemon* victim, CMove move);
	int				CalculateCatchRate();	//TODO: ������ �߰�
	
	bool			TryPokemonCatch();
};

#define BATTLE CBattleManager::GetInstance()