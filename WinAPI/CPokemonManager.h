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
	map<int, CMove*>	m_mapMoves;

public:
	CPokemon*	FindPokemon(int pokeNumber);
	CMove*		FindMove(int moveNumber);

private:
	void Init();
	void Release();
};

#define POKEMON CPokemonManager::GetInstance()

