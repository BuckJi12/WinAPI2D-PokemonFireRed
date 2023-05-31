#include "framework.h"
#include "CResourceManager.h"

#include "CPathManager.h"
#include "CImage.h"
#include "CSound.h"
#include "CPokemonResource.h"
#include "CEffect.h"

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

CEffect* CResourceManager::GetEffect(const PokemonType& key)
{
	return m_mapEffect[key];
}

void CResourceManager::AddEffect(PokemonType key, CEffect* effect)
{
	m_mapEffect.insert(make_pair(key, effect));
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
	// No.1 ÀÌ»óÇØ¾¾
	CPokemonResource* bulbasaur = new CPokemonResource;
	bulbasaur->SetImage(RESOURCE->LoadImg(L"Bulbasaur", L"Image\\Pokemon\\BulbasaurImage.png"));
	bulbasaur->SetIcon(RESOURCE->LoadImg(L"BulbasaurIcon", L"Image\\Pokemon\\BulbasaurIcon.png"));
	m_mapPokemonResource.insert(make_pair(1, bulbasaur));

	// No.2 ÀÌ»óÇØÇ®
	CPokemonResource* ivysaur = new CPokemonResource;
	ivysaur->SetImage(RESOURCE->LoadImg(L"Ivysaur", L"Image\\Pokemon\\IvysaurImage.png"));
	ivysaur->SetIcon(RESOURCE->LoadImg(L"IvysaurIcon", L"Image\\Pokemon\\IvysaurIcon.png"));
	m_mapPokemonResource.insert(make_pair(2, ivysaur));

	// No.2 ÀÌ»óÇØ²É
	CPokemonResource* venusaur = new CPokemonResource;
	venusaur->SetImage(RESOURCE->LoadImg(L"Venusaur", L"Image\\Pokemon\\VenusaurImage.png"));
	venusaur->SetIcon(RESOURCE->LoadImg(L"VenusaurIcon", L"Image\\Pokemon\\VenusaurIcon.png"));
	m_mapPokemonResource.insert(make_pair(3, venusaur));

	// No.4 ÆÄÀÌ¸®
	CPokemonResource* charmander = new CPokemonResource;
	charmander->SetImage(RESOURCE->LoadImg(L"Charmander", L"Image\\Pokemon\\CharmanderImage.png"));
	charmander->SetIcon(RESOURCE->LoadImg(L"CharmanderIcon", L"Image\\Pokemon\\CharmanderIcon.png"));
	m_mapPokemonResource.insert(make_pair(4, charmander));

	// No.5 ¸®ÀÚµå
	CPokemonResource* charmeleon = new CPokemonResource;
	charmeleon->SetImage(RESOURCE->LoadImg(L"CharmeleonImage", L"Image\\Pokemon\\CharmeleonImage.png"));
	charmeleon->SetIcon(RESOURCE->LoadImg(L"CharmeleonIcon", L"Image\\Pokemon\\CharmeleonIcon.png"));
	m_mapPokemonResource.insert(make_pair(5, charmeleon));

	// No.6 ¸®ÀÚ¸ù
	CPokemonResource* charizard = new CPokemonResource;
	charizard->SetImage(RESOURCE->LoadImg(L"CharizardImage", L"Image\\Pokemon\\CharizardImage.png"));
	charizard->SetIcon(RESOURCE->LoadImg(L"CharizardIcon", L"Image\\Pokemon\\CharizardIcon.png"));
	m_mapPokemonResource.insert(make_pair(6, charizard));

	// No.7 ²¿ºÎ±â 
	CPokemonResource* squirtle = new CPokemonResource;
	squirtle->SetImage(RESOURCE->LoadImg(L"Squirtle", L"Image\\Pokemon\\SquirtleImage.png"));
	squirtle->SetIcon(RESOURCE->LoadImg(L"SquirtleIcon", L"Image\\Pokemon\\SquirtleIcon.png"));
	m_mapPokemonResource.insert(make_pair(7, squirtle));

	// No.8 ¾î´ÏºÎ±â 
	CPokemonResource* wartortle = new CPokemonResource;
	wartortle->SetImage(RESOURCE->LoadImg(L"Wartortle", L"Image\\Pokemon\\WartortleImage.png"));
	wartortle->SetIcon(RESOURCE->LoadImg(L"WartortleIcon", L"Image\\Pokemon\\WartortleIcon.png"));
	m_mapPokemonResource.insert(make_pair(8, wartortle));

	// No.9 °ÅºÏ¿Õ 
	CPokemonResource* blastoise = new CPokemonResource;
	blastoise->SetImage(RESOURCE->LoadImg(L"Blastoise", L"Image\\Pokemon\\BlastoiseImage.png"));
	blastoise->SetIcon(RESOURCE->LoadImg(L"BlastoiseIcon", L"Image\\Pokemon\\BlastoiseIcon.png"));
	m_mapPokemonResource.insert(make_pair(9, blastoise));

	// No.10 Ä³ÅÍÇÇ 
	CPokemonResource* caterpie = new CPokemonResource;
	caterpie->SetImage(RESOURCE->LoadImg(L"Caterpie", L"Image\\Pokemon\\CaterpieImage.png"));
	caterpie->SetIcon(RESOURCE->LoadImg(L"CaterpieIcon", L"Image\\Pokemon\\CaterpieIcon.png"));
	m_mapPokemonResource.insert(make_pair(10, caterpie));

	// No.11 ´Üµ¥±â 
	CPokemonResource* metapod = new CPokemonResource;
	metapod->SetImage(RESOURCE->LoadImg(L"Metapod", L"Image\\Pokemon\\MetapodImage.png"));
	metapod->SetIcon(RESOURCE->LoadImg(L"MetapodIcon", L"Image\\Pokemon\\MetapodIcon.png"));
	m_mapPokemonResource.insert(make_pair(11, metapod));

	// No.12 ¹öÅÍÇÃ 
	CPokemonResource* butterfree = new CPokemonResource;
	butterfree->SetImage(RESOURCE->LoadImg(L"Butterfree", L"Image\\Pokemon\\ButterfreeImage.png"));
	butterfree->SetIcon(RESOURCE->LoadImg(L"ButterfreeIcon", L"Image\\Pokemon\\ButterfreeIcon.png"));
	m_mapPokemonResource.insert(make_pair(12, butterfree));

	// No.13 ÇÇÄ«Ãò 
	CPokemonResource* pikachu = new CPokemonResource;
	pikachu->SetImage(RESOURCE->LoadImg(L"Pikachu", L"Image\\Pokemon\\PikachuImage.png"));
	pikachu->SetIcon(RESOURCE->LoadImg(L"PikachuIcon", L"Image\\Pokemon\\PikachuIcon.png"));
	m_mapPokemonResource.insert(make_pair(13, pikachu));

	// No.14 ÆÒÅÒ 
	CPokemonResource* gengar = new CPokemonResource;
	gengar->SetImage(RESOURCE->LoadImg(L"Gengar", L"Image\\Pokemon\\GengarImage.png"));
	gengar->SetIcon(RESOURCE->LoadImg(L"GengarIcon", L"Image\\Pokemon\\GengarIcon.png"));
	m_mapPokemonResource.insert(make_pair(14, gengar));

	// No.15 Àá¸¸º¸ 
	CPokemonResource* snorlax = new CPokemonResource;
	snorlax->SetImage(RESOURCE->LoadImg(L"Snorlax", L"Image\\Pokemon\\SnorlaxImage.png"));
	snorlax->SetIcon(RESOURCE->LoadImg(L"SnorlaxIcon", L"Image\\Pokemon\\SnorlaxIcon.png"));
	m_mapPokemonResource.insert(make_pair(15, snorlax));

	// No.16 ¸Á³ª´¨ 
	CPokemonResource* dragonite = new CPokemonResource;
	dragonite->SetImage(RESOURCE->LoadImg(L"Dragonite", L"Image\\Pokemon\\DragoniteImage.png"));
	dragonite->SetIcon(RESOURCE->LoadImg(L"DragoniteIcon", L"Image\\Pokemon\\DragoniteIcon.png"));
	m_mapPokemonResource.insert(make_pair(16, dragonite));

	// No.17 ÇÁ¸®Á® 
	CPokemonResource* articuno = new CPokemonResource;
	articuno->SetImage(RESOURCE->LoadImg(L"Articuno", L"Image\\Pokemon\\ArticunoImage.png"));
	articuno->SetIcon(RESOURCE->LoadImg(L"ArticunoIcon", L"Image\\Pokemon\\ArticunoIcon.png"));
	m_mapPokemonResource.insert(make_pair(17, articuno));
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

	for (pair<PokemonType, CEffect*> effect : m_mapEffect)
	{
		delete effect.second;
	}
	m_mapEffect.clear();
}
