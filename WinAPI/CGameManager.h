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
	CMonsterBall*	m_ball;
	CMasterBall*	m_masterBall;

	bool			m_canMove;
	bool			m_debugMode;
	bool			m_canMeet;
	bool			m_playerGetStarting;
	int				m_randomValue;

public:
	float	m_meetTime;

	bool GetDebugMode();
	bool GetCanMove();
	bool GetCanMeet();
	bool GetPlayerGetStarting();
	int	 GetValue();

	void SetRandomValue();
	void SetPlayerGetStarting(bool get);
	void SetCanMove(bool canMove);

private:
	void GetMonsterBall();

private:
	void ChangeDebugMode();
	void Init();
	void Update();
	void Release();
};

#define GAME CGameManager::GetInstance()

