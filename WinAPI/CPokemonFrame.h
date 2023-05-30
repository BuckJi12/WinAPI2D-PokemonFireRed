#pragma once

class CPokemonFrame : public CGameObject
{
public:
	CPokemonFrame();
	virtual ~CPokemonFrame();

private:
	CImage*	m_pImageFrame;
	CImage*	m_pImagePokemon;

public:
	void SetImage(CImage* image);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

