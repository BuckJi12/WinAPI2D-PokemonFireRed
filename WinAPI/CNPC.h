#pragma once

class CNPC : public CGameObject
{
public:
	CNPC();
	virtual ~CNPC();

private:
	CImage*		m_pImage;
	CAnimator*	m_pAnimator;

public:
	CImage*		GetImage();
	CAnimator*	GetAnimator();

protected:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

