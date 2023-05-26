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
	// ========================== Æ÷ÄÏ¸ó =========================
	m_mapPokemons.insert(make_pair(1, new CBulbasaur()));		// ÀÌ»óÇØ¾¾
	m_mapPokemons.insert(make_pair(4, new CCharmander()));		// ÆÄÀÌ¸®
	m_mapPokemons.insert(make_pair(7, new CSquirtle()));		// ²¿ºÎ±â

	// ========================== ±â ¼ú ==========================

	m_mapMoves.insert(make_pair(1, new CTackle()));				// ¸öÅë¹ÚÄ¡±â
	m_mapMoves.insert(make_pair(2, new CEmber()));				// ºÒ²É¼¼·Ê
	m_mapMoves.insert(make_pair(3, new CWaterGun()));				// ¹°´ëÆ÷
	m_mapMoves.insert(make_pair(4, new CVineWhip()));				// µ¢ÄðÃ¤Âï
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
