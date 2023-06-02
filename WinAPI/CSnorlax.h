#pragma once

class CSnorlax : public CPokemon
{
public:
	CSnorlax();
	virtual ~CSnorlax();

	CSnorlax(const CSnorlax& snorlax);
	CSnorlax* Clone() override;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

