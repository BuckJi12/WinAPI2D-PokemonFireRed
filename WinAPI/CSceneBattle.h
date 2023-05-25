#pragma once
#include "CTurn.h"

class CImageObject;
class COpponentFloor;
class CPlayerThrowBall;
class CPlayerStatUI;
class CTurn;

enum class TurnSituation
{
	Change,
	MustChange,

	Size
};

class CSceneBattle : public CScene
{
public:
	CSceneBattle();
	virtual ~CSceneBattle();

private:
	map<PlayerAction, CTurn*>	m_mapTurns;
	CTurn*						m_curTurn;
	TurnSituation				m_curTurnSituation;

	CImageObject*				m_pImageBackGround;
	CImageObject*				m_pCursor;
	CPlayerStatUI*				m_pImagePlayerStatUI;

public:
	TurnSituation				GetCurSituation();
	CImageObject*				GetCursor();
	CPlayerStatUI*				GetPlayerUI();

	void						SetTurnSituation(TurnSituation situation);
	void						AddObjectThisScene(CGameObject* object);
	void						ChangeTurn(PlayerAction action);

private:
	void						CheckAddedGameObject();

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

