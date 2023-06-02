#pragma once

class CSceneMountain : public CScene
{
public:
	CSceneMountain();
	virtual ~CSceneMountain();

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

