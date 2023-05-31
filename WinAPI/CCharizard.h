#pragma once

class CCharizard : public CPokemon
{
public:
	CCharizard();
	virtual ~CCharizard();

	CCharizard(const CCharizard& charizard);

private:
	CMove* m_fireBlast;
	CMove* m_firePunch;
	CMove* m_thunderPunch;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

