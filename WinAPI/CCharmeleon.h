#pragma once

class CCharmeleon : public CPokemon
{
public:
	CCharmeleon();
	virtual ~CCharmeleon();

	CCharmeleon(const CCharmeleon& charmeleon);

private:
	CMove* m_ember;

public:
	void Evolution() override;
	void LearnMoveList() override;
	void Init() override;

private:
	void Update() override;
	void Render() override;
	void Release() override;
};

