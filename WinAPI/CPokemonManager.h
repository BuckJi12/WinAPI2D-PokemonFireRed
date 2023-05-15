#pragma once

class CPokemonManager : public SingleTon<CPokemonManager>
{
	friend SingleTon<CPokemonManager>;
	friend CCore;
private:
	CPokemonManager();
	virtual ~CPokemonManager();

private:
	map<int, CPokemon*> m_mapPokemons;

public:
	CPokemon* FindPokemon(int pokeNumber);

private:
	void Init();
	void Release();
};

#define POKEMON CPokemonManager::GetInstance()

