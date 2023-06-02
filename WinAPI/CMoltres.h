#pragma once

class CMoltres : public CPokemon
{
public:
	CMoltres();
	virtual ~CMoltres();

	CMoltres(const CMoltres& moltres);
	CMoltres* Clone() override;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

