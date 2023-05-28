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
	// ========================== ���ϸ� =========================
	m_mapPokemons.insert(make_pair(1, new CBulbasaur()));		// �̻��ؾ�
	m_mapPokemons.insert(make_pair(4, new CCharmander()));		// ���̸�
	m_mapPokemons.insert(make_pair(5, new CCharmeleon()));		// ���ڵ�
	m_mapPokemons.insert(make_pair(7, new CSquirtle()));		// ���α�
 }

void CPokemonManager::Release()
{
	for (auto pokemon : m_mapPokemons)
	{
		delete pokemon.second;
	}
}
