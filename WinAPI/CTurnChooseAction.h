#pragma once
#include "CTurn.h"

class CChooseWindow;

class CTurnChooseAction : public CTurn
{
public:
	CTurnChooseAction(CSceneBattle* battleScene);
	virtual ~CTurnChooseAction();

private:
	CChooseWindow*	m_pChooseWindow;

	int				m_curCount;

private:
	void CursorControl();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

