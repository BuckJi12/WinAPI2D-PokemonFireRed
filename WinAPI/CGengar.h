#pragma once

class CGengar : public CPokemon
{
public:
	CGengar();
	virtual ~CGengar();

	CGengar(const CGengar& gengar);

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

