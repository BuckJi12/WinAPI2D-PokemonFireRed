#pragma once
#include "CTurn.h"

class CImageObject;
class COpponentFloor;
class CPlayerThrowBall;
class CTurn;

class CSceneBattle : public CScene
{
public:
	CSceneBattle();
	virtual ~CSceneBattle();

private:
	CImageObject*		m_pImageBackGround;
	CImageObject*		m_pImagePlayerFloor;
	CImageObject*		m_pImageNoramUI;
	COpponentFloor*		m_pImageOpponentFloor;

	CPlayerThrowBall*	m_pImagePlayerThrow;

	map<PlayerAction, CTurn*> m_mapTurns;
	CTurn* m_curTurn;

	float				m_time;
private:
	void EnterInit();
	void TakeOutPlayerPokemon();

public:
	void AddObjectThisScene(CGameObject* object);
	void ChangeTurn(PlayerAction action);

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

