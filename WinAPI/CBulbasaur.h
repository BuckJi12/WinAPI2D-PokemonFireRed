#pragma once
class CBulbasaur : public CPokemon
{
public:
	CBulbasaur();
	virtual ~CBulbasaur();

	CBulbasaur(const CBulbasaur& bulbasaur);
	CBulbasaur* Clone() override;

public:
	void Evolution()		override;
	void LearnMoveList()	override;

private:
	void Init()				override;
	void Update()			override;
	void Render()			override;
	void Release()			override;
};

