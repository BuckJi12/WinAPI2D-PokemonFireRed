#include "framework.h"
#include "CPokemonManager.h"

CPokemonManager::CPokemonManager()
{
}

CPokemonManager::~CPokemonManager()
{
}

CPokemon* CPokemonManager::FindPokemon(int pokeNumber)
{
	return m_mapPokemons[pokeNumber];
}

void CPokemonManager::Init()
{
	m_mapPokemons.insert(make_pair(1, new CBulbasaur()));		// 이상해씨
	m_mapPokemons.insert(make_pair(4, new CCharmander()));		// 파이리
}

void CPokemonManager::Release()
{
	for (auto pokemon : m_mapPokemons)
	{
		delete pokemon.second;
	}
}
