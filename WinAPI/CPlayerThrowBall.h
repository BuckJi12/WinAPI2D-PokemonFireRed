#pragma once
#include "CImageObject.h"

class CPlayerThrowBall : public CImageObject
{
public:
	CPlayerThrowBall();
	virtual ~CPlayerThrowBall();

private:
	CAnimator*	m_pAnimator;
	Vector		m_point;
	bool		isThrew;

public:
	void Setting(Vector pos);
	void Play();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

