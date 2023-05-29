#pragma once

class CTitleAnimation : public CGameObject
{
public:
	CTitleAnimation();
	virtual ~CTitleAnimation();

private:
	CAnimator*	m_pAnimator;
	CImage*		m_pImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

