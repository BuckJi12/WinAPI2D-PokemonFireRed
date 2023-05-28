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
	// ========================== 포켓몬 =========================
	m_mapPokemons.insert(make_pair(1, new CBulbasaur()));		// 이상해씨
	m_mapPokemons.insert(make_pair(4, new CCharmander()));		// 파이리
	m_mapPokemons.insert(make_pair(5, new CCharmeleon()));		// 리자드
	m_mapPokemons.insert(make_pair(7, new CSquirtle()));		// 꼬부기
 }

void CPokemonManager::Release()
{
	for (auto pokemon : m_mapPokemons)
	{
		delete pokemon.second;
	}
}
