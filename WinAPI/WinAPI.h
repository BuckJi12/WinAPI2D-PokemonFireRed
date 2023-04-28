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
	Fight,
	ChooseMove,
	Change,
	ChoosePokemon,
	Bag,
	ChooseItem,
	Ball,
	Runaway,
	Check,
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

	Size
};