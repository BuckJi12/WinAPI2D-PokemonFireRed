#pragma once

class CScenePokemonList : public CScene
{
public:
	CScenePokemonList();
	virtual ~CScenePokemonList();

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

