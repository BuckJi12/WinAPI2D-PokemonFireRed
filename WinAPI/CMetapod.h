#pragma once

class CMetapod : public CPokemon
{
public:
	CMetapod();
	virtual ~CMetapod();

	CMetapod(const CMetapod& metapod);
	CMetapod* Clone() override;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

