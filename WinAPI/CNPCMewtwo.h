#pragma once
#include "CNPC.h"

class CNPCMewtwo : public CNPC
{
public:
	CNPCMewtwo();
	virtual ~CNPCMewtwo();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

