#pragma once
class CImage;

class CPokemonResource
{
public:
	CPokemonResource();
	virtual ~CPokemonResource();

private:
	CImage* m_pImage;
	CImage* m_pIcon;

public:
	CImage* GetImage();
	CImage* GetIcon();
	void SetImage(CImage* image);
	void SetIcon(CImage* icon);
};

