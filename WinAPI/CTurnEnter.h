#pragma once
#include "CTurn.h"

class CImageObject;
class COpponentFloor;
class CPlayerThrowBall;

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

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

