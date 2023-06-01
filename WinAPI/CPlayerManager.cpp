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
	CMonsterBall* monsterBall = new CMonsterBall;
	monsterBall->Init();
	AddItem(monsterBall, 5);
	CMasterBall* masterBall = new CMasterBall;
	masterBall->Init();
	AddItem(masterBall, 5);
	AddItem(masterBall, 2);
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

vector<CItem*> CPlayerManager::GetPlayerItemList()
{
	return m_pVecPlayerItems;
}

void CPlayerManager::CheckPokemonIndex(CPokemon* pokemon)
{
	auto iter = m_pVecPlayerPokemons.begin();
	for (CPokemon* pokemon : m_pVecPlayerPokemons)
	{
		//TODO: �� ������ ������ �ʿ��� ��
	}
}

void CPlayerManager::AddItem(CItem* item, int count)
{
	for (auto object : m_pVecPlayerItems)
	{
		if (object->GetItemData().name == item->GetItemData().name)
		{
			object->SetCount(object->GetItemData().count + count);
			return;
		}
	}

	item->SetCount(count);
	m_pVecPlayerItems.push_back(item);
}

void CPlayerManager::RemoveItem(CItem* item)
{
	for (int i = 0; i < m_pVecPlayerItems.size(); i++)
	{
		if (m_pVecPlayerItems[i] == item)
		{
			m_pVecPlayerItems.erase(m_pVecPlayerItems.begin() + i);
		}
	}
}

void CPlayerManager::PokemonSwap(int a, int b)
{
	if (a > m_pVecPlayerPokemons.size() - 1)
		return;
	if (b > m_pVecPlayerPokemons.size() - 1)
		return;

	CPokemon* temp = m_pVecPlayerPokemons[a];
	m_pVecPlayerPokemons[a] = m_pVecPlayerPokemons[b];
	m_pVecPlayerPokemons[b] = temp;
}

void CPlayerManager::DeletePokemon(int index)
{
	if (m_pVecPlayerPokemons.size() > 1)
	{
		// index�� ������ �� �ڸ�
		if (index == m_pVecPlayerPokemons.size() - 1)
		{
			m_pVecPlayerPokemons.pop_back();
			return;
		}
		else
		{
			PokemonSwap(index, index + 1);
			DeletePokemon(index + 1);
		}
	}
}

void CPlayerManager::RecoverPokemon()
{
	for (auto pokemon : m_pVecPlayerPokemons)
	{
		pokemon->Recover();
	}
}
