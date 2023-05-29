#pragma once

class CTitleText : public CGameObject
{
public:
	CTitleText();
	virtual ~CTitleText();

private:
	CAnimator*	m_pAnimator;
	CImage*		m_pImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

