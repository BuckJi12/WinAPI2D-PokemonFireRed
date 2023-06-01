#pragma once

class CCore;
class CSound;

class CSoundManager : public SingleTon<CSoundManager>
{
	friend SingleTon<CSoundManager>;
	friend CCore;
private:
	CSoundManager();
	virtual ~CSoundManager();

private:
	FMOD::System*					m_pSystem;	// 사운드 시스템
	map<PokemonType, CSound*>		m_mapSoundEffect;
	map<GroupScene, CSound*>		m_mapBGM;
	map<SpecialSound, CSound*>		m_mapSpecialSound;

public:
	System* GetSystem();

	CSound* GetMoveEffect(PokemonType type);
	CSound* GetBGM(GroupScene scene);
	CSound* GetSpecialSound(SpecialSound sound);
	void Play(CSound* pSound, float volume = 1.f, bool loop = false);
	void Stop(CSound* pSound);
	void Pause(CSound* pSound);
	void Resume(CSound* pSound);

private:
	void Init();
	void Update();
	void Release();
};

#define SOUND	CSoundManager::GetInstance()