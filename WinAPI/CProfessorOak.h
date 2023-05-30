#pragma once
#include "CNPC.h"

typedef void(*CallBackFunc)(DWORD_PTR);
class CProfessorOak : public CNPC
{
public:
	CProfessorOak();
	virtual ~CProfessorOak();

private:
	CallBackFunc	m_pCallBack;
	DWORD_PTR		m_pParam;

public:
	void SetCallBack(CallBackFunc callBackFunc, DWORD_PTR param);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

