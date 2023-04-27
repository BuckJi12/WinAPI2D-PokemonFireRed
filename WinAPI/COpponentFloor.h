#pragma once
#include "CImageObject.h"

class COpponentFloor : public CImageObject
{
public:
	COpponentFloor();
	virtual ~COpponentFloor();

private:
	Vector m_point;		// �ٴ��� ������ ����

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

