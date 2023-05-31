#pragma once

class CZapdos : public CPokemon
{
public:
	CZapdos();
	virtual ~CZapdos();

	CZapdos(const CZapdos& zapdos);

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

