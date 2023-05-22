#include "framework.h"
#include "CPlayerManager.h"

#include "CPokemon.h"

CPlayerManager::CPlayerManager()
{
}

CPlayerManager::~CPlayerManager()
{
}

void CPlayerManager::Init()
{
	CPokemon* charmander = new CCharmander();
	charmander->SetPokemonStat(5);
	CPokemon* bulbasaur = new CBulbasaur;
	bulbasaur->SetPokemonStat(7);
	CPokemon* bulbasaur3 = new CBulbasaur;
	bulbasaur3->SetPokemonStat(77);
	AddPokemonToPlayer(charmander);
	AddPokemonToPlayer(bulbasaur);
	AddPokemonToPlayer(bulbasaur3);
}

void CPlayerManager::Update()
{
}

void CPlayerManager::Release()
{
}

void CPlayerManager::AddPokemonToPlayer(CPokemon* pokemon)
{
	if (m_pVecPlayerPokemons.size() > 5)
	{
		return;
		//TODO: 포켓몬이 6마리일시 자동으로 PC로 보내기
	}
	pokemon->SetOwner(PokemonOwner::Player);
	m_pVecPlayerPokemons.push_back(pokemon);
}

CPokemon* CPlayerManager::GetPlayerFirstPokemon()
{
	for (CPokemon* pokemon : m_pVecPlayerPokemons)
	{
		// 지금 포켓몬이 기절 상태면 다음 포켓몬을 확인한다.
		if (pokemon->GetCurState() == PokemonState::Faint)
			continue;

		return pokemon;
	}
	// 모든 포켓몬이 기절 상태일 경우 null 반환
	return nullptr;
}

vector<CPokemon*> CPlayerManager::GetPlayerPokemonList()
{
	return m_pVecPlayerPokemons;
}

vector<CItem> CPlayerManager::GetPlayerItemList()
{
	return m_vecPlayerItems;
}

void CPlayerManager::CheckPokemonIndex(CPokemon* pokemon)
{
	auto iter = m_pVecPlayerPokemons.begin();
	for (CPokemon* pokemon : m_pVecPlayerPokemons)
	{
		//TODO: 비교 연산자 재정의 필요할 듯
	}
}

void CPlayerManager::AddItem(CItem item, int count)
{
	for (auto item : m_vecPlayerItems)
	{
		if (item.GetItemData().name == item.GetItemData().name)
		{
			item.SetCount(item.GetItemData().count + count);
			return;
		}
	}

	item.SetCount(count);
	m_vecPlayerItems.push_back(item);
}
