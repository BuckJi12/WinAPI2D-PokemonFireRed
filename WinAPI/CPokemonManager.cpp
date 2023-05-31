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
	m_mapPokemons.insert(make_pair(2, new CIvysaur()));			// 이상해풀
	m_mapPokemons.insert(make_pair(3, new CVenusaur()));		// 이상해꽃
	m_mapPokemons.insert(make_pair(4, new CCharmander()));		// 파이리
	m_mapPokemons.insert(make_pair(5, new CCharmeleon()));		// 리자드
	m_mapPokemons.insert(make_pair(6, new CCharizard()));		// 리자몽
	m_mapPokemons.insert(make_pair(7, new CSquirtle()));		// 꼬부기
	m_mapPokemons.insert(make_pair(8, new CWartortle()));		// 어니부기
	m_mapPokemons.insert(make_pair(9, new CBlastoise()));		// 거북왕
	m_mapPokemons.insert(make_pair(10, new CCaterpie()));		// 캐터피
	m_mapPokemons.insert(make_pair(11, new CMetapod()));		// 단데기
	m_mapPokemons.insert(make_pair(12, new CButterfree()));		// 버터플
	m_mapPokemons.insert(make_pair(13, new CPikachu()));		// 피카츄
	m_mapPokemons.insert(make_pair(14, new CGengar()));			// 팬텀
	m_mapPokemons.insert(make_pair(15, new CSnorlax()));		// 잠만보
	m_mapPokemons.insert(make_pair(16, new CDragonite()));		// 망나뇽
 }

void CPokemonManager::Release()
{
	for (auto pokemon : m_mapPokemons)
	{
		delete pokemon.second;
	}
}
