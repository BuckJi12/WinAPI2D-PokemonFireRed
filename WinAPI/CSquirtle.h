#pragma once

class CSquirtle : public CPokemon
{
public:
	CSquirtle();
	virtual ~CSquirtle();

	CSquirtle(const CSquirtle& squirtle);
	CSquirtle* Clone() override;

public:
	void Evolution() override;
	void LearnMoveList() override;

	void Init() override;

private:
	void Update() override;
	void Render() override;
	void Release() override;
};

