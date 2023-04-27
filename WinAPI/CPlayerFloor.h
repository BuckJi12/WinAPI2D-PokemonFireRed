#pragma once
#include "CImageObject.h"

class CPlayerFloor : public CImageObject
{
public:
	CPlayerFloor();
	virtual ~CPlayerFloor();

private:
	Vector m_point;		// �ٴ��� ������ ����

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

