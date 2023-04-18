#pragma once
class CPlayer;
class CImageObject;

class CScenePlayerHome1F : public CScene
{
public:
	CScenePlayerHome1F();
	virtual ~CScenePlayerHome1F();

private:
	CPlayer* m_pPlayer;
	CImageObject* m_pImageBackGround;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

