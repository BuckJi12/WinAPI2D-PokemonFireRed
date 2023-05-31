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
	m_mapPokemons.insert(make_pair(2, new CIvysaur()));			// �̻���Ǯ
	m_mapPokemons.insert(make_pair(3, new CVenusaur()));		// �̻��ز�
	m_mapPokemons.insert(make_pair(4, new CCharmander()));		// ���̸�
	m_mapPokemons.insert(make_pair(5, new CCharmeleon()));		// ���ڵ�
	m_mapPokemons.insert(make_pair(6, new CCharizard()));		// ���ڸ�
	m_mapPokemons.insert(make_pair(7, new CSquirtle()));		// ���α�
	m_mapPokemons.insert(make_pair(8, new CWartortle()));		// ��Ϻα�
	m_mapPokemons.insert(make_pair(9, new CBlastoise()));		// �źϿ�
	m_mapPokemons.insert(make_pair(10, new CCaterpie()));		// ĳ����
	m_mapPokemons.insert(make_pair(11, new CMetapod()));		// �ܵ���
 }

void CPokemonManager::Release()
{
	for (auto pokemon : m_mapPokemons)
	{
		delete pokemon.second;
	}
}
