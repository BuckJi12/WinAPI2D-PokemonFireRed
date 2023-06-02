#pragma once

class CMewtwo : public CPokemon
{
public:
	CMewtwo();
	virtual ~CMewtwo();

	CMewtwo(const CMewtwo& mewtwo);
	CMewtwo* Clone() override;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

