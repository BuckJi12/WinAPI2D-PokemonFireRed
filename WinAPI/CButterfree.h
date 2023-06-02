#pragma once

class CButterfree : public CPokemon
{
public:
	CButterfree();
	virtual ~CButterfree();

	CButterfree(const CButterfree& butterfree);
	CButterfree* Clone() override;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

