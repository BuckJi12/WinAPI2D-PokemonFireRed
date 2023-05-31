#pragma once

class CBlastoise : public CPokemon
{
public:
	CBlastoise();
	virtual ~CBlastoise();

	CBlastoise(const CBlastoise& blastoise);

private:
	CMove* m_hydroPump;

public:
	void Evolution() override;
	void LearnMoveList() override;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

