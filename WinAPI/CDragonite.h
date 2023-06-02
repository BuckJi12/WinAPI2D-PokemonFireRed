#pragma once

class CDragonite : public CPokemon
{
public:
	CDragonite();
	virtual ~CDragonite();

	CDragonite(const CDragonite& dragonite);
	CDragonite* Clone() override;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

