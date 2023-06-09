#pragma once
#include "CItem.h"

class CCore;
class CPokemon;

class CPlayerManager : public SingleTon<CPlayerManager>
{
	friend SingleTon<CPlayerManager>;
	friend CCore;
private:
	CPlayerManager();
	virtual ~CPlayerManager();

private:
	vector<CPokemon*>	m_pVecPlayerPokemons;
	vector<CItem*>		m_pVecPlayerItems;

private:
	void				Init();
	void				Update();
	void				Release();

public:
	void				AddPokemonToPlayer(CPokemon* pokemon);
	void				CheckPokemonIndex(CPokemon* pokemon);
	void				AddItem(CItem* item, int count);
	void				RemoveItem(CItem* item);
	void				PokemonSwap(int a, int b);
	void				DeletePokemon(int index);
	void				RecoverPokemon();
	CPokemon*			GetPlayerFirstPokemon();
	vector<CPokemon*>	GetPlayerPokemonList();
	vector<CItem*>		GetPlayerItemList();

};

#define PLAYER CPlayerManager::GetInstance()