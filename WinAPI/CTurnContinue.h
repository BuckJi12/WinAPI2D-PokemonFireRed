#pragma once
#include "CTurn.h"

class CImageObject;

class CTurnContinue : public CTurn
{
public:
	CTurnContinue(CSceneBattle* battleScene);
	virtual ~CTurnContinue();

private:
	CImageObject*	m_pImageContinue;

	int				m_curCount;

private:
	void CurSorControl();

public:
	void Init()    override;
	void Enter()   override;
	void Update()  override;
	void Exit()    override;
	void Release() override;
};

