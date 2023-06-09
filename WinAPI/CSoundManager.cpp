#include "framework.h"
#include "CSoundManager.h"

#include "CSound.h"

CSoundManager::CSoundManager()
{
	m_pSystem = nullptr;
}

CSoundManager::~CSoundManager()
{
}

System* CSoundManager::GetSystem()
{
	return m_pSystem;
}

CSound* CSoundManager::GetMoveEffect(PokemonType type)
{
	return m_mapSoundEffect[type];
}

CSound* CSoundManager::GetBGM(GroupScene scene)
{
	return m_mapBGM[scene];
}

CSound* CSoundManager::GetSpecialSound(SpecialSound sound)
{
	return m_mapSpecialSound[sound];
}

void CSoundManager::Play(CSound* pSound, float volume, bool loop)
{
	FMOD_RESULT result;

	FMOD_MODE mode;
	result = pSound->m_pSound->getMode(&mode);
	assert(FMOD_OK == result && L"Get mode failed");

	if (mode & FMOD_LOOP_NORMAL && (pSound->IsPlaying() || pSound->IsPaused()))
	{
		result = pSound->m_pChannel->stop();
		assert(FMOD_OK == result && L"Stop sound failed");
	}

	if (loop)
		result = pSound->m_pSound->setMode(FMOD_LOOP_NORMAL);
	else
		result = pSound->m_pSound->setMode(FMOD_LOOP_OFF);

	assert(FMOD_OK == result && L"Set Loop failed");

	result = m_pSystem->playSound(pSound->m_pSound, nullptr, false, &(pSound->m_pChannel));
	assert(FMOD_OK == result && L"Play sound failed");

	result = pSound->m_pChannel->setVolume(volume);
	assert(FMOD_OK == result && L"Set volume failed");
}

void CSoundManager::Stop(CSound* pSound)
{
	if (!pSound->IsPlaying())
		return;

	FMOD_RESULT result = pSound->m_pChannel->stop();
	assert(FMOD_OK == result && L"Stop sound failed");
}

void CSoundManager::Pause(CSound* pSound)
{
	if (pSound->IsPaused())
		return;

	FMOD_RESULT result = pSound->m_pChannel->setPaused(true);
	assert(FMOD_OK == result && L"SetPaused failed");
}

void CSoundManager::Resume(CSound* pSound)
{
	if (!pSound->IsPaused())
		return;

	FMOD_RESULT result = pSound->m_pChannel->setPaused(true);
	assert(FMOD_OK == result && L"Resume failed");
}

void CSoundManager::Init()
{
	// 사운드 시스템 생성
	FMOD_RESULT result;
	result = System_Create(&m_pSystem);
	assert(FMOD_OK == result && L"Create sound system falied");

	result = m_pSystem->init(32, FMOD_INIT_NORMAL, nullptr);
	assert(FMOD_OK == result && L"Init sound system falied");


	// ==================================== 사운드 =======================================

	CSound* normalSound = RESOURCE->LoadSound(L"NormalSound", L"Sound\\Effect\\Normal.mp3");
	m_mapSoundEffect.insert(make_pair(PokemonType::Normal, normalSound));
	CSound* fireSound = RESOURCE->LoadSound(L"FireSound", L"Sound\\Effect\\Fire.mp3");
	m_mapSoundEffect.insert(make_pair(PokemonType::Fire, fireSound));
	CSound* waterSound = RESOURCE->LoadSound(L"WaterSound", L"Sound\\Effect\\Water.mp3");
	m_mapSoundEffect.insert(make_pair(PokemonType::Water, waterSound));
	CSound* grassSound = RESOURCE->LoadSound(L"GrassSound", L"Sound\\Effect\\Grass.mp3");
	m_mapSoundEffect.insert(make_pair(PokemonType::Grass, grassSound));
	CSound* electricSound = RESOURCE->LoadSound(L"ElectricSound", L"Sound\\Effect\\Electric.mp3");
	m_mapSoundEffect.insert(make_pair(PokemonType::Electric, electricSound));
	CSound* psychicSound = RESOURCE->LoadSound(L"PsychicSound", L"Sound\\Effect\\Psychic.mp3");
	m_mapSoundEffect.insert(make_pair(PokemonType::Psychic, psychicSound));
	CSound* iceSound = RESOURCE->LoadSound(L"IceSound", L"Sound\\Effect\\Ice.mp3");
	m_mapSoundEffect.insert(make_pair(PokemonType::Ice, iceSound));

	CSound* palletTown = RESOURCE->LoadSound(L"PalletTownBGM", L"Sound\\BGM\\PalletTown.wav");
	m_mapBGM.insert(make_pair(GroupScene::PalletTown, palletTown));
	CSound* battle = RESOURCE->LoadSound(L"BattleBGM", L"Sound\\BGM\\Battle.wav");
	m_mapBGM.insert(make_pair(GroupScene::Battle, battle));
	CSound* center = RESOURCE->LoadSound(L"CenterBGM", L"Sound\\BGM\\Center.wav");
	m_mapBGM.insert(make_pair(GroupScene::Center, center));
	CSound* oakLab = RESOURCE->LoadSound(L"OakLabBGM", L"Sound\\BGM\\ProfessorOak.wav");
	m_mapBGM.insert(make_pair(GroupScene::OakLab, oakLab));
	CSound* title = RESOURCE->LoadSound(L"TitleBGM", L"Sound\\BGM\\Title.wav");
	m_mapBGM.insert(make_pair(GroupScene::Title, title));
	CSound* viridianTown = RESOURCE->LoadSound(L"ViridianTown", L"Sound\\BGM\\Viridian.wav");
	m_mapBGM.insert(make_pair(GroupScene::ViridianTown, viridianTown));
	CSound* mountain = RESOURCE->LoadSound(L"mountainBGM", L"Sound\\BGM\\Mountain.mp3");
	m_mapBGM.insert(make_pair(GroupScene::Mountain, mountain));

	CSound* victory = RESOURCE->LoadSound(L"VictorySound", L"Sound\\Special\\Victory.wav");
	m_mapSpecialSound.insert(make_pair(SpecialSound::Victory, victory));
	CSound* heal = RESOURCE->LoadSound(L"HealSound", L"Sound\\Special\\Heal.wav");
	m_mapSpecialSound.insert(make_pair(SpecialSound::Heal, heal));
}

void CSoundManager::Update()
{
	FMOD_RESULT result = m_pSystem->update();
	assert(FMOD_OK == result && L"Update sound system falied");
}

void CSoundManager::Release()
{
	if (nullptr != m_pSystem)
	{
		m_pSystem->release();
		m_pSystem->close();
	}

	for (auto moveSound : m_mapSoundEffect)
	{
		delete moveSound.second;
	}
	m_mapSoundEffect.clear();

	for (auto BGM : m_mapBGM)
	{
		delete BGM.second;
	}
	m_mapBGM.clear();
}
