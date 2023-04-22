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
	bool debugMode;
	bool canMeet;
	int randomValue;

private:
	void ChangeDebugMode();
	void SetRandomValue();
	void Init();
	void Update();
	void Release();
};

#define GAME CGameManager::GetInstance()

