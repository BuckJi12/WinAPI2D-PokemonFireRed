#pragma once

typedef void(*CallBackFunc)(DWORD_PTR);
class CNPC : public CGameObject
{
public:
	CNPC();
	virtual ~CNPC();

protected:
	CImage*			m_pImage;
	CAnimator*		m_pAnimator;
	CallBackFunc	m_pCallBack;
	DWORD_PTR		m_pParam;

	bool			m_talking;
public:
	CImage*		GetImage();
	CAnimator*	GetAnimator();
	void SetCallBack(CallBackFunc callBackFunc, DWORD_PTR param);

protected:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

