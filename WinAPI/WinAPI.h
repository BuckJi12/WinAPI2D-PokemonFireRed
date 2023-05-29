#pragma once

#include "resource.h"

//========================================
//##    ��������(�ν��Ͻ�, ������ �ڵ�)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

//========================================
//##			������ ����				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	800
#define	WINSIZEY	600
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//========================================
//##			���Ӿ� �׷�				##
//========================================

enum class GroupScene
{
	Title,
	TileTool,
	Stage01,
	PlayerHome2F,
	PlayerHome1F,
	PalletTown,
	OakLab,
	Route01,
	ViridianTown,
	Center,

	PokemonList,
	PrevScene,
	Battle,
	None,
	Size,
};

//========================================
//##				���̾�				##
//========================================

enum class Layer
{
	Default,
	Tile,
	Player,
	Wall,
	Environment,
	Environment2,
	Environment3,

	Ui,
	Size,
};

//========================================
//##				Ÿ��					##
//========================================

enum class TypeTile
{
	None,
	Wall,
	Platform,
	Meeting,

	Size,
};

//========================================
//##			���ϸ� Ÿ��				##
//========================================

enum class PokemonType
{
	None,
	Normal,
	Fire,
	Water,
	Electric,
	Grass,
	Ice,
	Fight,
	Poison,
	Ground,
	Flying,
	Psychic,
	Bug,
	Rock,
	Ghost,
	Dragon,
	Dark,
	Steel,

	Size,
};

//========================================
//##			�÷��̾� �ൿ				##
//========================================

enum class PlayerAction
{
	Enter,
	PlayerReady,
	ChooseAction,
	Battle,
	ChooseMove,
	Change,
	ChoosePokemon,
	Bag,
	Catch,
	Runaway,
	Continue,
	Result,
	None,

	Size
};

//========================================
//##			����	 ����				##
//========================================

enum class FirstAttack
{
	Player,
	Oppoent,
	OnlyOpponent,

	Size
};

//========================================
//##			����	 ��Ȳ				##
//========================================

enum class BattleSituation
{
	Player_CanNot_Battle,
	Opponet_CanNot_Battle,
	BothSide_Can_Battle,

	Size
};

//========================================
//##			��ȹ ���				##
//========================================

enum class CatchResult
{
	Fail1,
	Fail2,
	Fail3,
	Success,

	Size
};

//========================================
//##			��Ʋ ���				##
//========================================

enum class BattleResult
{
	Win,
	Lose,

	Size
};