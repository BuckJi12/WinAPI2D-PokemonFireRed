#pragma once
#include "CTurn.h"

class CImageObject;
class CChooseMoveWindow;

class CTurnChooseMove : public CTurn
{
public:
	CTurnChooseMove(CSceneBattle* battleScene);
	virtual ~CTurnChooseMove();

private:
	CChooseMoveWindow*	m_pImageChooseMove;
	int					m_curCount;

private:
	void CursorControl();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

