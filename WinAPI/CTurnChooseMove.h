#pragma once
#include "CTurn.h"

class CImageObject;

class CTurnChooseMove : public CTurn
{
public:
	CTurnChooseMove(CSceneBattle* battleScene);
	virtual ~CTurnChooseMove();

private:
	CImageObject* m_pImageChooseMove;

private:
	void CursorControl();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

