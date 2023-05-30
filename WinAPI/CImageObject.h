#pragma once
#include "CGameObject.h"

class CImage;

class CImageObject : public CGameObject
{
public:
	CImageObject();
	virtual ~CImageObject();

protected:
	CImage* m_pImage;

public:
	CImage* GetImage();
	void SetImage(CImage* pImage);

protected:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

