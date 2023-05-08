#pragma once
#include "CTurn.h"

class CChooseWindow;

enum class CursorState
{
	Fight,
	Bag,
	Pokemon,
	Runaway,

	Size
};

class CTurnChooseAction : public CTurn
{
public:
	CTurnChooseAction(CSceneBattle* battleScene);
	virtual ~CTurnChooseAction();

private:
	CChooseWindow*	m_pChooseWindow;
	CursorState		m_cursorState;

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

