#pragma once
#include "CImageObject.h"

enum class BallMode
{
	None,
	TakeOut,
	Catch,
	CollsionTarget,
	Catching,

	Size
};

class CBallObject : public CImageObject
{
public:
	CBallObject();
	virtual ~CBallObject();

private:
	Vector m_targetPos;
	Vector m_difValue;
	BallMode m_curMode;
	CAnimator* m_pAnimator;
	//TODO: º¼ Ãß°¡
	
	bool m_isDown;
	bool m_isStop;

private:
	void BallMove();

public:
	void SetMode(BallMode mode);
	void SetBall();
	void SetAnimation(const wstring& aniName);
	void SetTarget(CGameObject* object);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

