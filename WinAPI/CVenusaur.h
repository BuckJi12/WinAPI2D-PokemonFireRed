#pragma once

class CVenusaur : public CPokemon
{
public:
	CVenusaur();
	virtual ~CVenusaur();

	CVenusaur(const CVenusaur& venusaur);

private:
	CMove* m_leafStorm;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

