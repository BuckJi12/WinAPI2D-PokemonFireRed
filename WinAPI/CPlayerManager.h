#pragma once

class CCore;

class CPlayerManager : public SingleTon<CPlayerManager>
{
	friend SingleTon<CPlayerManager>;
	friend CCore;
private:
	CPlayerManager();
	virtual ~CPlayerManager();

private:
	vector<CPokemon*> m_pVecPlayerPokemons;
	// TODO: °¡¹æ

private:
	void	Init();
	void	Update();
	void	Release();

	void	AddPokemonToPlayer(CPokemon* pokemon);
	void	CheckPokemonIndex(CPokemon* pokemon);
	CPokemon* GetPlayerFirstPokemon();

};

#define PLAYER CPlayerManager::GetInstance()