#pragma once

class CWartortle : public CPokemon
{
public:
	CWartortle();
	virtual ~CWartortle();

	CWartortle(const CWartortle& wartortle);
	CWartortle* Clone() override;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

