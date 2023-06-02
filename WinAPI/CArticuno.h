#pragma once

class CArticuno : public CPokemon
{
public:
	CArticuno();
	virtual ~CArticuno();

	CArticuno(const CArticuno& articuno);
	CArticuno* Clone() override;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

