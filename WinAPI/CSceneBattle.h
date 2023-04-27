#pragma once

class CImageObject;
class CPlayerThrowBall;

class CSceneBattle : public CScene
{
public:
	CSceneBattle();
	virtual ~CSceneBattle();

private:
	CImageObject* m_pImageBackGround;
	CImageObject* m_pImagePlayerFloor;
	CImageObject* m_pImageOpponentFloor;
	CImageObject* m_pImageNoramUI;

	CPlayerThrowBall* m_pImagePlayerThrow;

private:
	void EnterInit();

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};
