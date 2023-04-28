#pragma once
#include "CImageObject.h"

class COpponentFloor : public CImageObject
{
public:
	COpponentFloor();
	virtual ~COpponentFloor();

private:
	Vector			m_point;		// 바닥이 도착할 지점
	CGameObject*	m_pChild;

public:
	void SetChild(CGameObject* object);

private:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

