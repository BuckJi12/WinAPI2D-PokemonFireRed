#pragma once

class CCaterpie : public CPokemon
{
public:
	CCaterpie();
	virtual ~CCaterpie();

	CCaterpie(const CCaterpie& caterpie);

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

