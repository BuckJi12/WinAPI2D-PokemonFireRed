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

	Size,
};