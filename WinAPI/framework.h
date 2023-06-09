﻿// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "commdlg.h"

// C++ 표준 라이브러리
#include <clocale>
#include <chrono>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <cassert>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// Direct2D
#include <d2d1.h>
#include <dwrite.h>
#include <wincodec.h>
#pragma comment(lib, "D2D1.lib")
#pragma comment(lib, "Dwrite.lib")

using namespace D2D1;

// FMOD
#include "FMOD/inc/fmod.hpp"
#pragma comment(lib,"FMOD/lib/fmod_vc.lib")

using namespace FMOD;

// Util
#include "SingleTon.h"
#include "Struct.h"
#include "Logger.h"

// Engine 1.0
#include "WinAPI.h"

#include "CCore.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CInputManager.h"
#include "CSceneManager.h"
#include "CEventManager.h"
#include "CCollisionManager.h"
#include "CPathManager.h"
#include "CResourceManager.h"
#include "CCameraManager.h"
#include "CUIManager.h"
#include "CSoundManager.h"
#include "CGameManager.h"
#include "CPlayerManager.h"
#include "CBattleManager.h"
#include "CPokemonManager.h"

// Asset
#include "CGameObject.h"
#include "CScene.h"

// Resource
#include "CResource.h"
#include "CImage.h"
#include "CSound.h"
#include "CAnimation.h"
#include "CTile.h"

// UI
#include "CUI.h"
#include "CButton.h"
#include "CPanel.h"
#include "CTextBox.h"

// Component
#include "CComponent.h"
#include "CAnimator.h"
#include "CCollider.h"
#include "ISubject.h"
#include "IObserver.h"
#include "CSubject.h"

// Item
#include "CMonsterBall.h"
#include "CMasterBall.h"

// Pokemon
#include "CPokemon.h"
#include "CMove.h"
#include "CPokemonResource.h"

#include "CBulbasaur.h"			// No.1		이상해씨
#include "CIvysaur.h"			// No.2		이상해풀
#include "CVenusaur.h"			// No.3		이상해꽃
#include "CCharmander.h"		// No.4		파이리
#include "CCharmeleon.h"		// No.5		리자드
#include "CCharizard.h"			// No.6		리자몽
#include "CSquirtle.h"			// No.7		꼬부기
#include "CWartortle.h"			// No.8		어니부기
#include "CBlastoise.h"			// No.9		거북왕
#include "CCaterpie.h"			// No.10	캐터피
#include "CMetapod.h"			// No.11	단데기
#include "CButterfree.h"		// No.12	버터플
#include "CPikachu.h"			// No.13    피카츄
#include "CGengar.h"			// No.14	팬텀
#include "CSnorlax.h"			// No.15	잠만보
#include "CDragonite.h"			// No.16	망나뇽
#include "CArticuno.h"			// No.17	프리져
#include "CZapdos.h"			// No.18	썬더
#include "CMoltres.h"			// No.19	파이어
#include "CMewtwo.h"			// No.20	뮤츠

// Pokemon Moves
// Normal
#include "CTackle.h"
#include "CHyperBeam.h"
// Fire
#include "CEmber.h"
#include "CFirePunch.h"
#include "CFireBlast.h"
// Water
#include "CWaterGun.h"
#include "CWaterPulse.h"
#include "CHydroPump.h"
// Grass
#include "CVineWhip.h"
#include "CLeafStrom.h"
// Psychic
#include "CPsychic.h"
// Ice
#include "CIceBeam.h"
#include "CIcePunch.h"
// Lightning
#include "CThunderBolt.h"
#include "CThunderPunch.h"

// Effect
#include "CEffect.h"

#include "CEffectNormal.h"
#include "CEffectGrass.h"
#include "CEffectFire.h"
#include "CEffectWater.h"
#include "CEffectLightning.h"
#include "CEffectIce.h"
#include "CEffectPsyChic.h"