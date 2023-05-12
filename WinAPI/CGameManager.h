#pragma once

class CCore;

class CGameManager : public SingleTon<CGameManager>
{
	friend SingleTon<CGameManager>;
	friend CCore;

private:
	CGameManager();
	virtual ~CGameManager();

public:
	float	m_meetTime;
	bool	m_debugMode;
	bool	m_canMeet;
	int		m_randomValue;

	void SetRandomValue();

private:
	void ChangeDebugMode();
	void Init();
	void Update();
	void Release();
};

#define GAME CGameManager::GetInstance()

