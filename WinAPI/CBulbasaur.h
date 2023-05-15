#pragma once
class CBulbasaur : public CPokemon
{
public:
	CBulbasaur();
	virtual ~CBulbasaur();

public:
	void Evolution()		override;
	void LearnMoveList()	override;

private:
	void Init()				override;
	void Update()			override;
	void Render()			override;
	void Release()			override;
};

