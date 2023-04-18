#pragma once

class CWarp : public CGameObject
{
public:
	CWarp();
	virtual ~CWarp();

private:
	GroupScene m_destination;

public:
	void SetDestination(GroupScene destination);
private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
	
	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

