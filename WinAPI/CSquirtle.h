#pragma once

class CSquirtle : public CPokemon
{
public:
	CSquirtle();
	virtual ~CSquirtle();

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

