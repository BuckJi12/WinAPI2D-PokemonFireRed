#pragma once
#include "CTurn.h"

class CImageObject;
class COpponentFloor;
class CPlayerThrowBall;
class COpponentStatUI;

class CTurnEnter : public CTurn
{
public:
	CTurnEnter(CSceneBattle* battleScene);
	virtual ~CTurnEnter();

private:
	CImageObject*		m_pImagePlayerFloor;
	CImageObject*		m_pImageNoramUI;
	COpponentFloor*		m_pImageOpponentFloor;
	CPlayerThrowBall*	m_pImagePlayerThrow;
	COpponentStatUI*	m_pImageOppStatUI;
	bool				m_OpponentSpawn;

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

