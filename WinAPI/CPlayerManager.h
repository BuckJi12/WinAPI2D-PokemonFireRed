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
	vector<CItem>		m_vecPlayerItems;

private:
	void				Init();
	void				Update();
	void				Release();

public:
	void				AddPokemonToPlayer(CPokemon* pokemon);
	void				CheckPokemonIndex(CPokemon* pokemon);
	void				AddItem(CItem item, int count);
	CPokemon*			GetPlayerFirstPokemon();
	vector<CPokemon*>	GetPlayerPokemonList();
	vector<CItem>		GetPlayerItemList();

};

#define PLAYER CPlayerManager::GetInstance()