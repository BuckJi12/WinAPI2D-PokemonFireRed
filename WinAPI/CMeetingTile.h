#pragma once

class CMeetingTile : public CTile
{
public:
	CMeetingTile();
	virtual ~CMeetingTile();

private:
	CImage* m_pImage;
	CAnimator* m_pAnimator;
	float m_time;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

private:
	void OnCollisionEnter(CCollider* pOther) override;
	void OnCollisionStay(CCollider* pOther) override;
	void OnCollisionExit(CCollider* pOther) override;
};
