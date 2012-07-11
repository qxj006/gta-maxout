#pragma once

#include "main.h"

//enable/disable defines
#define INSTALL_PATCH_FOR_VCPATH_INSTANCE

// standard include directives
#include <Windows.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

// utilies directives for general usuage
#include "CSingleton.h"
#include "CMemory.h"
#include "Utilities.h"
#include "D3D8Hook.h"
#include "CCustomFont.h"

// to be disengaged
#include "GamePatches.h"

// game sdk includes
#include "GameVC\CVector.h"
#include "GameVC\CVector2D.h"
#include "GameVC\CCurves.h"
#include "GameVC\CGeneral.h"

// game definations and new patches includes
#include "GameVC\CPathFindHook.h"
#include "GameVC\CGameHookManager.h"
#include "GameVC\CGameVariables.h"
#include "GameVC\RenderWare.h"
#include "GameVC\CMatrix.h"
#include "GameVC\CWorld.h"
#include "GameVC\CCamera.h"
#include "GameVC\GameVC.h"
#include "GameVC\CFileMgr.h"
#include "GameVC\CDebug.h"
#include "GameVC\CFileLoader.h"
#include "GameVC\CTheZones.h"
#include "GameVC\CCullZones.h"
#include "GameVC\CPathFind.h"
#include "GameVC\CTheCarGenerators.h"
#include "GameVC\CFont.h"
#include "GameVC\CTxdStore.h"
#include "GameVC\CSprite2D.h"
#include "GameVC\CommonDefinations.h"
#include "GameVC\CAutoPilot.h"
#include "GameVC\CCarCtrl.h"
#include "GameVC\CPed.h"