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

CMove* CPokemonManager::FindMove(int moveNumber)
{
	return m_mapMoves[moveNumber];
}

void CPokemonManager::Init()
{
	// ========================== ���ϸ� =========================
	m_mapPokemons.insert(make_pair(1, new CBulbasaur()));		// �̻��ؾ�
	m_mapPokemons.insert(make_pair(4, new CCharmander()));		// ���̸�
	m_mapPokemons.insert(make_pair(7, new CSquirtle()));		// ���α�

	// ========================== �� �� ==========================

	m_mapMoves.insert(make_pair(1, new CTackle()));				// �����ġ��
	m_mapMoves.insert(make_pair(2, new CEmber()));				// �Ҳɼ���
	m_mapMoves.insert(make_pair(3, new CWaterGun()));				// ������
	m_mapMoves.insert(make_pair(4, new CVineWhip()));				// ����ä��
}

void CPokemonManager::Release()
{
	for (auto pokemon : m_mapPokemons)
	{
		delete pokemon.second;
	}

	for (auto move : m_mapMoves)
	{
		delete move.second;
	}
}
