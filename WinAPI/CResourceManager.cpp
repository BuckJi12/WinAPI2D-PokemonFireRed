#include "framework.h"
#include "CResourceManager.h"

#include "CPathManager.h"
#include "CImage.h"
#include "CSound.h"
#include "CPokemonResource.h"

CResourceManager::CResourceManager()
{
}

CResourceManager::~CResourceManager()
{
}

CImage* CResourceManager::FindImg(const wstring& key)
{
	auto iter = m_umapImage.find(key);
	if (iter == m_umapImage.end())
		return nullptr;
	else
		return m_umapImage[key];
}

CImage* CResourceManager::LoadImg(const wstring& key, const wstring& fileName)
{
	CImage* pImage = FindImg(key);
	if (nullptr != pImage)
		return pImage;

	wstring filePath = GETPATH + fileName;
	pImage = new CImage;
	pImage->Load(filePath);
	pImage->SetKey(key);
	pImage->SetPath(filePath);
	m_umapImage.insert(make_pair(key, pImage));

	return pImage;
}

CImage* CResourceManager::LoadImgWithPath(const wstring& key, const wstring& path)
{
	CImage* pImage = FindImg(key);
	if (nullptr != pImage)
		return pImage;

	wstring filePath = path;
	pImage = new CImage;
	pImage->Load(filePath);
	pImage->SetKey(key);
	pImage->SetPath(filePath);
	m_umapImage.insert(make_pair(key, pImage));

	return pImage;
}

CSound* CResourceManager::FindSound(const wstring& key)
{
	auto iter = m_umapSound.find(key);
	if (iter == m_umapSound.end())
		return nullptr;
	else
		return m_umapSound[key];
}

CSound* CResourceManager::LoadSound(const wstring& key, const wstring& fileName)
{
	CSound* pSound = FindSound(key);
	if (nullptr != pSound)
		return pSound;

	wstring filePath = GETPATH + fileName;
	pSound = new CSound;
	pSound->Load(filePath);
	pSound->SetKey(key);
	pSound->SetPath(filePath);
	m_umapSound.insert(make_pair(key, pSound));

	return pSound;
}

CPokemonResource* CResourceManager::GetPokemonResource(const int& key)
{
	auto iter = m_mapPokemonResource.find(key);
	if (iter == m_mapPokemonResource.end())
		return nullptr;
	else
		return m_mapPokemonResource[key];
}

void CResourceManager::Init()
{
	// No. 1 이상해씨
	CPokemonResource* bulbasaur = new CPokemonResource;
	bulbasaur->SetImage(RESOURCE->LoadImg(L"Bulbasaur", L"Image\\Pokemon\\BulbasaurImage.png"));
	bulbasaur->SetIcon(RESOURCE->LoadImg(L"BulbasaurIcon", L"Image\\Pokemon\\BulbasaurIcon.png"));
	m_mapPokemonResource.insert(make_pair(1, bulbasaur));

	// No.4 파이리
	CPokemonResource* charmander = new CPokemonResource;
	charmander->SetImage(RESOURCE->LoadImg(L"Charmander", L"Image\\Pokemon\\CharmanderImage.png"));
	charmander->SetIcon(RESOURCE->LoadImg(L"CharmanderIcon", L"Image\\Pokemon\\CharmanderIcon.png"));
	m_mapPokemonResource.insert(make_pair(4, charmander));
}

void CResourceManager::Release()
{
	for (pair<wstring, CImage*> image : m_umapImage)
	{
		delete image.second;
	}
	m_umapImage.clear();

	for (pair<wstring, CSound*> sound : m_umapSound)
	{
		delete sound.second;
	}
	m_umapSound.clear();

	for (pair<int, CPokemonResource*> pokemon : m_mapPokemonResource)
	{
		delete pokemon.second;
	}
	m_mapPokemonResource.clear();
}
