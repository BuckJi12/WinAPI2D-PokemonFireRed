#pragma once

class CPlayer;
class CImageObject;
class CWarp;

class CSceneRoute01 : public CScene
{
public:
	CSceneRoute01();
	virtual ~CSceneRoute01();

private:
	CPlayer* m_pPlayer;
	CImageObject* m_pImageBackGround;
	CWarp* m_pWarp;
	CWarp* m_pWarp2;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

