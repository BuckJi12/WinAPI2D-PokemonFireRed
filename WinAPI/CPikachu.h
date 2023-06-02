#pragma once

class CPikachu : public CPokemon
{
public:
	CPikachu();
	virtual ~CPikachu();

	CPikachu(const CPikachu& pikachu);
	CPikachu* Clone() override;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

