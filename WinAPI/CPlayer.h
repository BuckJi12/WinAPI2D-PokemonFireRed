#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;
class CState;

enum class PlayerState
{
	Idle,
	Walk,
	Run,

	Size
};

enum class PlayerDir
{
	Down,
	Up,
	Left,
	Right,

	Size
};

class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

private:
	map<PlayerState, CState*> m_mapState;
	CAnimator* m_pAnimator;
	PlayerState m_curState;
	PlayerDir m_curDir;

public:
	CAnimator* GetAnimator();
	PlayerDir GetDir();

	void ChangeState(PlayerState state);
	void ChangeDir(PlayerDir dir);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};