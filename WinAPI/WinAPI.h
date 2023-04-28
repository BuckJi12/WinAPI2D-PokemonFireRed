#pragma once

#include "resource.h"

//========================================
//##    전역변수(인스턴스, 윈도우 핸들)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

//========================================
//##			윈도우 설정				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	800
#define	WINSIZEY	600
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//========================================
//##			게임씬 그룹				##
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
//##				레이어				##
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
//##				타일					##
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
//##			포켓몬 타입				##
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
//##			플레이어 행동				##
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
//##			선제	 공격				##
//========================================

enum class FirstAttack
{
	Player,
	Oppoent,

	Size
};