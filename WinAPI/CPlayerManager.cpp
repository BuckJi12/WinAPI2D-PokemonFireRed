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
	AddPokemonToPlayer(charmander);
	AddPokemonToPlayer(bulbasaur);
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
		//TODO: ���ϸ��� 6�����Ͻ� �ڵ����� PC�� ������
	}
	pokemon->SetOwner(PokemonOwner::Player);
	m_pVecPlayerPokemons.push_back(pokemon);
}

CPokemon* CPlayerManager::GetPlayerFirstPokemon()
{
	for (CPokemon* pokemon : m_pVecPlayerPokemons)
	{
		// ���� ���ϸ��� ���� ���¸� ���� ���ϸ��� Ȯ���Ѵ�.
		if (pokemon->GetCurState() == PokemonState::Faint)
			continue;

		return pokemon;
	}
	// ��� ���ϸ��� ���� ������ ��� null ��ȯ
	return nullptr;
}

vector<CPokemon*> CPlayerManager::GetPlayerPokemonList()
{
	return m_pVecPlayerPokemons;
}

void CPlayerManager::CheckPokemonIndex(CPokemon* pokemon)
{
	auto iter = m_pVecPlayerPokemons.begin();
	for (CPokemon* pokemon : m_pVecPlayerPokemons)
	{
		//TODO: �� ������ ������ �ʿ��� ��
	}
}
