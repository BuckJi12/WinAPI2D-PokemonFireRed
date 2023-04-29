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
	map<PlayerAction, CTurn*> m_mapTurns;
	CTurn* m_curTurn;

	CImageObject*		m_pImageBackGround;

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

