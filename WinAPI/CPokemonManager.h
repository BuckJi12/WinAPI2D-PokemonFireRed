#pragma once

class CPokemonManager : public SingleTon<CPokemonManager>
{
	friend SingleTon<CPokemonManager>;
	friend CCore;
private:
	CPokemonManager();
	virtual ~CPokemonManager();

private:


public:


private:
	void Init();
	void Release();
};

#define POKEMON CPokemonManager::GetInstance()

