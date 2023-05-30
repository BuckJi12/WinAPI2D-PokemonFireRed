#pragma once

class CCore;

class CGameManager : public SingleTon<CGameManager>
{
	friend SingleTon<CGameManager>;
	friend CCore;

private:
	CGameManager();
	virtual ~CGameManager();

private:
	bool	m_canMove;
	bool	m_debugMode;
	bool	m_canMeet;
	int		m_randomValue;

public:
	float	m_meetTime;

	bool GetDebugMode();
	bool GetCanMove();
	bool GetCanMeet();
	int	 GetValue();

	void SetRandomValue();
	void SetCanMove(bool canMove);

private:
	void ChangeDebugMode();
	void Init();
	void Update();
	void Release();
};

#define GAME CGameManager::GetInstance()

