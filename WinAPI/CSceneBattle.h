#pragma once

class CImageObject;
class COpponentFloor;
class CPlayerThrowBall;

class CSceneBattle : public CScene
{
public:
	CSceneBattle();
	virtual ~CSceneBattle();

private:
	CImageObject*		m_pImageBackGround;
	CImageObject*		m_pImagePlayerFloor;
	CImageObject*		m_pImageNoramUI;
	COpponentFloor*		m_pImageOpponentFloor;

	CPlayerThrowBall*	m_pImagePlayerThrow;

	float				m_time;
private:
	void EnterInit();
	void TakeOutPlayerPokemon();
private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

