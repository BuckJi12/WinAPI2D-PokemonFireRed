#pragma once
class CPlayer;
class CImageObject;
class CWarp;

class CScenePlayerHome1F : public CScene
{
public:
	CScenePlayerHome1F();
	virtual ~CScenePlayerHome1F();

private:
	CPlayer* m_pPlayer;
	CImageObject* m_pImageBackGround;
	CWarp* m_pWarp;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

