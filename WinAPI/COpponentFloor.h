#pragma once
#include "CImageObject.h"

class COpponentFloor : public CImageObject
{
public:
	COpponentFloor();
	virtual ~COpponentFloor();

private:
	Vector			m_point;		// �ٴ��� ������ ����
	CGameObject*	m_pChild;

public:
	void SetChild(CGameObject* object);

private:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;
};

