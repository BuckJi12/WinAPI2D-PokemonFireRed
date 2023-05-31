#pragma once

class CIvysaur : public CPokemon
{
public:
	CIvysaur();
	virtual ~CIvysaur();

	CIvysaur(const CIvysaur& ivysaur);

private:
	CMove* m_vineWhip;

public:
	void Evolution() override;
	void LearnMoveList() override;
	void Init() override;

private:
	void Update() override;
	void Render() override;
	void Release() override;
};

