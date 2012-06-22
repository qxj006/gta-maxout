#include "../StdInc.h"

template<> CPathFindHook * CSingleton<CPathFindHook>::m_pSingleton = NULL;

CPathFind* pThePaths = NULL;

CPathFindHook::CPathFindHook() {
    //pThePaths = new CPathFind();   
    pThePaths = (CPathFind*)0x9B6E5C;
}

CPathFindHook::~CPathFindHook() {
    RemoveHook();
    //delete pThePaths;
    //pThePaths = NULL;
}

int _nHookDetachedNodeIndex;
int _nHookAttachedNodeIndex;
CPathNode* _pHookPathNode;
wchar_t* _pwszHookString;
int* _pHookEditValue;
void* _pHookReturn;
DWORD _dwIndexWithSize;
DWORD _dwHookArgOne, _dwHookArgTwo;
CPathFind* _pHookPathFind;
CDetachedNode* _pHookDetachedNode;
DWORD _dwHookLocal;
float _fHookFloatOne, _fHookFloatTwo;
int _nHookReturn;
#define ASMJMP(x) {_asm push x _asm retn} 

//-----------------------------------------------------------
// These are hooks inside CAutopilot::ModifySpeed. They make
// sure the coordinates values are calculated properly with 
// the new path system
//-----------------------------------------------------------

//418D48
void _declspec(naked) HookModSpeedGetDetachedNormalXOne(void) {
    _asm mov _nHookDetachedNodeIndex, eax
    _asm pushad
    
    _nHookReturn = pThePaths->m_DetachedNodes[_nHookDetachedNodeIndex].NormalVecX;
    _dwIndexWithSize = _nHookDetachedNodeIndex * sizeof(CDetachedNode);

    _asm popad
    _asm mov ecx, _dwIndexWithSize
    _asm mov eax, _nHookReturn
    ASMJMP(418D59h)
}

//418D68
void _declspec(naked) HookModSpeedGetDetachedYCoorOne(void) {
    _asm mov _nHookDetachedNodeIndex, eax
    _asm pushad

    _fHookFloatOne = 0.0099999998f;
    _nHookReturn = pThePaths->m_DetachedNodes[_nHookDetachedNodeIndex].wY;
    _dwIndexWithSize = _nHookDetachedNodeIndex * sizeof(CDetachedNode);

    _asm popad
    _asm fmul _fHookFloatOne
    _asm mov eax, _nHookReturn
    _asm mov ebp, _dwIndexWithSize
    ASMJMP(418D80h)
}

//418DAA
void _declspec(naked) HookModSpeedGetDetachedNormalXTwo(void) {
    _asm mov _dwIndexWithSize, ebp
    _asm pushad
    
    _nHookReturn = pThePaths->m_DetachedNodes[_dwIndexWithSize / sizeof(CDetachedNode)].NormalVecX;

    _asm popad
    _asm mov eax, _nHookReturn
    ASMJMP(418DB1h)
}

//418DCB
void _declspec(naked) HookModSpeedGetDetachedXCoorOne(void) {
    _asm mov _dwIndexWithSize, ebp
    _asm pushad

    _nHookReturn = pThePaths->m_DetachedNodes[_dwIndexWithSize/sizeof(CDetachedNode)].wX;

    _asm popad
    _asm mov eax, _nHookReturn
    ASMJMP(418DD2h)
}

//418DEF
void _declspec(naked) HookModSpeedGetDetachedNormalYOne(void) {
    _asm mov _dwIndexWithSize, ebp
    _asm pushad

    _nHookReturn = pThePaths->m_DetachedNodes[_dwIndexWithSize/sizeof(CDetachedNode)].NormalVecY;

    _asm popad
    _asm mov eax, _nHookReturn
    ASMJMP(418DF6h)
}

//418E21
void _declspec(naked) HookModSpeedGetDetachedYCoorTwo(void) {
    _asm mov _nHookDetachedNodeIndex, eax
    _asm pushad

    _nHookReturn = pThePaths->m_DetachedNodes[_nHookDetachedNodeIndex].wY;
    _dwIndexWithSize = _nHookDetachedNodeIndex * sizeof(CDetachedNode);

    _asm popad
    _asm mov eax, _nHookReturn
    _asm mov edx, _dwIndexWithSize
    ASMJMP(418E32h)
}

//418E48
void _declspec(naked) HookModSpeedGetDetachedXCoorTwo(void) {
    _asm mov _dwIndexWithSize, edx
    _asm pushad

    _nHookReturn = pThePaths->m_DetachedNodes[_dwIndexWithSize/sizeof(CDetachedNode)].wX;

    _asm popad
    _asm mov eax, _nHookReturn
    ASMJMP(418E4Fh)
}

//418E7C
void _declspec(naked) HookModSpeedGetDetachedNormalYTwo(void) {
    _asm mov _dwIndexWithSize, ecx
    _asm pushad

    _nHookReturn = pThePaths->m_DetachedNodes[_dwIndexWithSize/sizeof(CDetachedNode)].NormalVecY;

    _asm popad
    _asm mov eax, _nHookReturn
    ASMJMP(418E83h)
}

//418EB8
void _declspec(naked) HookModSpeedGetDetachedNormalYThree(void) {
    _asm mov _nHookDetachedNodeIndex, eax
    _asm pushad

    _nHookReturn = pThePaths->m_DetachedNodes[_nHookDetachedNodeIndex].NormalVecY;
    _dwIndexWithSize = _nHookDetachedNodeIndex * sizeof(CDetachedNode);

    _asm popad
    _asm mov eax, _nHookReturn
    _asm mov ebp, _dwIndexWithSize
    ASMJMP(418ECAh)
}

//418EE9
void _declspec(naked) HookModSpeedGetDetachedNormalXThree(void) {
    _asm mov _dwIndexWithSize, ebp
    _asm pushad

    _nHookReturn = pThePaths->m_DetachedNodes[_dwIndexWithSize/sizeof(CDetachedNode)].NormalVecX;

    _asm popad
    _asm mov eax, _nHookReturn
    ASMJMP(418EF0h)
}

//418F15
void _declspec(naked) HookModSpeedGetDetachedNormalYFour(void) {
    _asm mov _nHookDetachedNodeIndex, eax
    _asm pushad

    _nHookReturn = pThePaths->m_DetachedNodes[_nHookDetachedNodeIndex].NormalVecY;
    _dwIndexWithSize = _nHookDetachedNodeIndex * sizeof(CDetachedNode);

    _asm popad
    _asm mov eax, _nHookReturn
    _asm mov edx, _dwIndexWithSize
    ASMJMP(418F26h)
}

//418F45
void _declspec(naked) HookModSpeedGetDetachedNormalXFour(void) {
    _asm mov _dwIndexWithSize, edx
    _asm pushad

    _nHookReturn = pThePaths->m_DetachedNodes[_dwIndexWithSize/sizeof(CDetachedNode)].NormalVecX;

    _asm popad
    _asm mov eax, _nHookReturn
    ASMJMP(418F4Ch)
}

// ---------------------------------------------------------------------
// These hooks are inside CCarCtrl::GenerateOneEmergencyServicesCar.
// They make sure coordinates of Pathfind member are attached properly
//----------------------------------------------------------------------

//41C4F1
void _declspec(naked) HookGenEmerCarCheckVehicleType(void) {
    _asm mov _nHookAttachedNodeIndex, ecx
    _asm pushad

    if(pThePaths->m_AttachedPaths[_nHookAttachedNodeIndex].bitIsVehicleBoat) {
        _asm popad
        ASMJMP(41C531h)
    }

    _asm popad
    ASMJMP(41C4FFh)
}

//41C6A5
void _declspec(naked) HookGenEmerCarGetAttachedZCoorsOne(void) {
    _asm mov esi, [esp+68h]
    _asm mov ecx, [esp+64h]
    _asm lea edx, [esp+28h]
    _asm mov _dwHookArgOne, esi
    _asm mov _dwHookArgTwo, ecx
    _asm pushad

    _nHookReturn = pThePaths->m_AttachedPaths[_dwHookArgOne].wZ;

    _asm popad
    _asm mov eax, _nHookReturn
    _asm push 0
    _asm push 0
    _asm mov [esp+28h], eax
    _asm pushad

    _fHookFloatOne = 0.125f;
    _nHookReturn = pThePaths->m_AttachedPaths[_dwHookArgTwo].wZ;

    _asm popad
    _asm fild dword ptr [esp+28h]
    _asm fmul _fHookFloatOne
    _asm mov eax, _nHookReturn
    ASMJMP(41C6EBh)
}

//----------------------------------------------------------------
// This is a hook inside CCarCtrl::FindLinksToGoWithTheseNodes.
// It replaces the entire original function by jump to this 
// right after the function starts. This function seems to get 
// loaded when the a chasing cop car stops right near the player.
// To-Do: Change into a grid type setup
//----------------------------------------------------------------

//41CC20
void _cdecl HookFindLinksToGoWithTheseNodes(CVehicle* pVehicle) {
    _dwHookArgOne = pVehicle->field_1A6;
    CDebug::DebugAddText("HookFindLinksToGoWithTheseNodes");

    if (_dwHookArgOne) {
        _asm mov eax, _dwHookArgOne
        _asm push eax
        _asm mov eax, 649A30h
        _asm call eax
        _asm pop eax
    }
    
    int nConnectedPointInfo = pThePaths->m_AttachedPaths[pVehicle->Autopilot.dwStartingNode].wRouteInfoIndex;
    int _nLoop = 0;

    for(int _nLoop = 0; _nLoop < 12 && pVehicle->Autopilot.dwFollowingNode != (pThePaths->AttachedPointsInfo[_nLoop + nConnectedPointInfo] & CPathFind::eATTACHEDPOINTSINFONODEINDEXONLY); _nLoop++);
    pVehicle->Autopilot.dwMainNodeLastSet = pThePaths->DetachedPointsInfo[_nLoop + nConnectedPointInfo];
    if(pVehicle->Autopilot.dwStartingNode >= pVehicle->Autopilot.dwFollowingNode) {
        pVehicle->Autopilot.iIsNodeSame = 1;
    }
    else {
        pVehicle->Autopilot.iIsNodeSame = -1;
    }

    int nStartNode = pVehicle->Autopilot.dwStartingNode;
    int nFoundNode, nFoundDetachedNode;

    if(pThePaths->m_AttachedPaths[nStartNode].bitUnkCount4To7 == 1) {
        nFoundNode = 0;
        nFoundDetachedNode = pThePaths->DetachedPointsInfo[pThePaths->m_AttachedPaths[nStartNode].wRouteInfoIndex];
    }
    else {
        nFoundNode = -1;
        float fPrevCoefficient = 999999.88f;
        CPathNode* pPathNodeStart = &pThePaths->m_AttachedPaths[nStartNode];
        CVector vecStartNode((float)(pPathNodeStart->wX) / 8.0f, (float)(pPathNodeStart->wY) / 8.0f, (float)(pPathNodeStart->wZ) / 8.0f);

        for(int j = 0; j < pThePaths->m_AttachedPaths[nStartNode].bitUnkCount4To7; j++) {
            int nConnectedNextNode = pThePaths->AttachedPointsInfo[j+ pThePaths->m_AttachedPaths[nStartNode].wRouteInfoIndex] & CPathFind::eATTACHEDPOINTSINFONODEINDEXONLY;
            if(nConnectedNextNode == pVehicle->Autopilot.dwFollowingNode) {
                continue;
            }
            
            CVector vecNextConnectedNode;
            vecNextConnectedNode.x = (float)(pThePaths->m_AttachedPaths[nConnectedNextNode].wX) / 8.0f;
            vecNextConnectedNode.y = (float)(pThePaths->m_AttachedPaths[nConnectedNextNode].wY) / 8.0f;
            vecNextConnectedNode.z = (float)(pThePaths->m_AttachedPaths[nConnectedNextNode].wZ) / 8.0f;
            float fCurrentCoefficient;
            RwV3d* vPosADDR = &pVehicle->__parent.__parent.matrix.rwMatrix.vPos;
            _asm mov eax, vPosADDR
            _asm push eax
            _asm lea eax, [vecNextConnectedNode]
            _asm push eax
            _asm lea eax, [vecStartNode]
            _asm push eax
            _asm mov eax, 414090h
            _asm call eax
            _asm fstp fCurrentCoefficient
            if(fCurrentCoefficient < fPrevCoefficient) {
                nFoundNode = j;
                fPrevCoefficient = fCurrentCoefficient;
            }
        }
        nFoundDetachedNode = pThePaths->DetachedPointsInfo[nFoundNode + pPathNodeStart->wRouteInfoIndex];
    }
    pVehicle->Autopilot.dwDetachedIndex = nFoundDetachedNode;
    if((pThePaths->AttachedPointsInfo[nFoundNode + pThePaths->m_AttachedPaths[nStartNode].wRouteInfoIndex] & CPathFind::eATTACHEDPOINTSINFONODEINDEXONLY) >= nStartNode) {
        pVehicle->Autopilot.field_29 = 1;
    }
    else {
        pVehicle->Autopilot.field_29 = -1;
    }
}

//-----------------------------------------------------------------------
// This is a hook inside CCarCtrl::JoinCarWithRoadSystemGotoCoors.
// It fixes the instructions which subtracts the pathnode with the first
// pathnode element in the ThePaths and divides them by the size of
// CPathNode to get the index.
//-----------------------------------------------------------------------

//41CF52
void _declspec(naked) HookJoinCarWithRoadFixPathPointerSubtract(void) {
    _asm mov _pHookPathNode, edx
    _asm pushad

    _nHookAttachedNodeIndex = ((uint32_t)_pHookPathNode - (uint32_t)&pThePaths->m_AttachedPaths[0])/ sizeof(CPathNode);

    _asm popad
    _asm mov ecx, _nHookAttachedNodeIndex
    _asm mov [ebx+128h], ecx
    _asm lea ecx, [ebx+128h]
    _asm mov eax, 418CA0h
    _asm call eax
    _asm mov edx, [ebx+178h]
    _asm mov _pHookPathNode, edx
    _asm pushad

    _nHookAttachedNodeIndex = ((uint32_t)_pHookPathNode - (uint32_t)&pThePaths->m_AttachedPaths[0])/ sizeof(CPathNode);

    _asm popad
    _asm mov ecx, _nHookAttachedNodeIndex
    ASMJMP(41CF97h)
}

//-----------------------------------------------------------------------------
// List Of Functions Hooked
// 1.  CPathFind::Init                 -FINE GRAINED
// 2.  CPathFind::PreparePathDataForType-THOROUGH REVISION AND DUMP TEST NEEDED
// 3.  CPathFind::StoreNodeInfoPed     -FINE GRAINED
// 4.  CPathFind::StoreNodeInfoCar     -FINE GRAINED
// 5.  CPathFind::ArrangeOneNodeList   -FINE GRAINED
// 6.  CFileLoader::LoadScene          -FINE GRAINED
// 7.  CPathFind::PreparePathData      -FINE GRAINED
// 8.  CPathFind::AllocatePathFindInfoMem- FINE GRAINED
// 9.  CPathFind::AddNodeToList - FINE GRAINED
// 10. CPathFind::RemoveNodeFromList - FINE GRAINED
// 11. CPathFind::FindNodeClosestToCoors - REVISION NEEDED
//          -can be optimized by setting up a grid system.
//          -work is needed in improving generation per calls
// 12. CPathFind::DoPathSearch - REVISION NEEDED
// 13. CPathFind::RemoveBadStartNode   - REVISION DONE
// 14. CPathFind::FindNextNodeWandering -REVISION NEEDED
// 15. CPathFind::NewGenerateCarCreationCoors - Optimization needed, finding new nodes - work is needed in improving generation per calls
// 16. CPathFind::GeneratePedCreationCoors - FINE GRAINED - work is needed in improving generation per calls
// 17. CPathFind::TestCoorsCloseness - FINE GRAINED
// 18. CPathFind::CalcRoadDensity - FINE GRAINED
//          This functions calculates the sum of displacement between car nodes inside an area.
//          The number is the divided by the area of the game (2500.0) to get the actual density
// 19. CPathFind::FindNodeClosestToCoorsFavourDirection - REVISION NEEEDED
//          This function calculates the nearest node favouring the direction an entity is heading
//          or if not specified the x/straight direction of the entity
//          -can be optimized using a grid system
// 20. CPathFind::TestCrossesRoad
// 21. CPathFind::TestForPedTrafficLight
//-------------------------------------------------------------------------------

void CPathFindHook::ApplyHook() {
    void (CPathFind::*p_mPreparePathDataForType)(uint8_t bytePathDataFor, CTempNode* pTempNode, CPathInfoForObject* pUnusedPathInfos, float fUnkRange, CPathInfoForObject* pPathInfosForObject, int nGroupNodesForObject);
    void (CPathFind::*p_mInit)(void);
    void (CPathFind::*p_mAllocatePathFindInfoMem)(void);
    void (CPathFind::*p_mPreparePathData)(void);
    void (CPathFind::*p_mDoPathSearch)(int iPathDataFor, float fOriginX, float fOriginY, float fOriginZ, int iFirstNode, float fDestX, float fDestY, float fDestZ, CPathNode **pIntermediateNodeList, short *pSteps, short sMaxSteps, void *pVehicle, float *pfDistance, float fMaxRadius, int iLastNode); //pVehicle, pfDistance and iLastNode are ununsed
    int (CPathFind::*p_mFindNodeClosestToCoors)(float fX, float fY, float fZ, unsigned char iPathDataFor, float fRangeCoefficient, bool bCheckIgnored, bool bCheckRestrictedAccess, bool bCheckUnkFlagFor2, bool bIsVehicleBoat);
    void (CPathFind::*p_mRemoveNodeFromList)(CPathNode *pRemoveNode);
    void (CPathFind::*p_mAddNodeToList)(CPathNode *pTargetNode, int iParamDisplacement);
    void (CPathFind::*p_mRemoveBadStartNode)(float fX, float fY, float fZ, CPathNode **pIntermediateNodeList, short *pSteps);
    void (CPathFind::*p_mFindNextNodeWandering)(unsigned char iPathDataFor, float fX, float fY, float fZ, CPathNode** pCurrentNode, CPathNode** pNextNode, uint8_t bytePreviousDirection, uint8_t *byteNewDirection);
    bool (CPathFind::*p_mNewGenerateCarCreationCoors)(float fX, float fY, float fDirectionVecX, float fDirectionVecY, float fRange, float fZlookUp, bool bShouldSpawnPositiveDirection, CVector *pVecPosition, int *aMainNodeIndex, int *aSubNodeIndex, float *aNodeRangeDiffCoeff, char bDontCheckIgnored);
    bool (CPathFind::*p_mGeneratePedCreationCoors)(float fX, float fY, float fRangeForRand, float fRange, float fRange1, float fRange2, CVector *pVecOutPosition, int *aStartNodeIndex, int *aFollowNodeIndex, float *frand, RwMatrix *rwMatrix);
    bool (CPathFind::*p_mTestCoorsCloseness)(float fDestinationX, float fDestinationY, float fDestinationZ, uint8_t uiPathDataFor, float fOriginX, float fOriginY, float fOriginZ);
    float (CPathFind::*p_mCalcRoadDensity)(float fX, float fY);
    int (CPathFind::*p_mFindNodeClosestToCoorsFavourDirection)(float fX, float fY, float fZ, uint8_t uiPathDataFor, float fLookAtX, float fLookAtY);
    bool (CPathFind::*p_mTestCrossesRoad)(CPathNode* pStartNode, CPathNode* pConnectedNode);
    bool (CPathFind::*p_mTestForPedTrafficLight)(CPathNode* pStartNode, CPathNode* pConnectedNode);

    float (CDetachedNode::*p_mCalculateLaneDistance)();
    // CDetachedNode::CalculateLaneDistance - REVISION NEEDED

    p_mInit = &CPathFind::Init;
    p_mAllocatePathFindInfoMem = &CPathFind::AllocatePathFindInfoMem;
    p_mPreparePathData = &CPathFind::PreparePathData;
    p_mPreparePathDataForType = &CPathFind::PreparePathDataForType;

    p_mDoPathSearch = &CPathFind::DoPathSearch;
    p_mFindNodeClosestToCoors = &CPathFind::FindNodeClosestToCoors;
    p_mRemoveNodeFromList = &CPathFind::RemoveNodeFromList;
    p_mAddNodeToList = &CPathFind::AddNodeToList;
    p_mRemoveBadStartNode = &CPathFind::RemoveBadStartNode;
    p_mFindNextNodeWandering = &CPathFind::FindNextNodeWandering;
    p_mNewGenerateCarCreationCoors = &CPathFind::NewGenerateCarCreationCoors;
    p_mGeneratePedCreationCoors = &CPathFind::GeneratePedCreationCoors;
    p_mTestCoorsCloseness = &CPathFind::TestCoorsCloseness;
    p_mCalcRoadDensity = &CPathFind::CalcRoadDensity;
    p_mFindNodeClosestToCoorsFavourDirection = &CPathFind::FindNodeClosestToCoorsFavourDirection;
    p_mTestCrossesRoad = &CPathFind::TestCrossesRoad;
    p_mTestForPedTrafficLight = &CPathFind::TestForPedTrafficLight;

    p_mCalculateLaneDistance = &CDetachedNode::CalculateLaneDistance;
    // Disable Unused CPathFind Treadables in CFileLoader::LoadObjectInstance
    CMemory::NoOperation(0x48AE30, 44);
    // Hooks in CGame::Init
    CMemory::InstallCallHook(0x4A4C0C, (DWORD)(void*&)p_mInit, ASM_CALL);

    CMemory::NoOperation(0x4A4C16, 5); // Remove One Unused Parameter
    CMemory::InstallCallHook(0x4A4C1B, (DWORD)(void*&)p_mAllocatePathFindInfoMem, ASM_CALL);    
    CMemory::InstallCallHook(0x4A4CE7, (DWORD)(void*&)p_mPreparePathData, ASM_CALL);
    // Install PreparePathDataHook
    CMemory::InstallCallHook(0x43BF3C, (DWORD)(void*&)p_mPreparePathDataForType, ASM_CALL);
    CMemory::InstallCallHook(0x43BF74, (DWORD)(void*&)p_mPreparePathDataForType, ASM_CALL);

    CMemory::InstallCallHook(0x439070, (DWORD)(void*&)p_mDoPathSearch, ASM_JMP);
    CMemory::InstallCallHook(0x437150, (DWORD)(void*&)p_mFindNodeClosestToCoors, ASM_JMP);
    CMemory::InstallCallHook(0x437330, (DWORD)(void*&)p_mAddNodeToList, ASM_JMP);
    CMemory::InstallCallHook(0x4375C0, (DWORD)(void*&)p_mRemoveNodeFromList, ASM_JMP);
    CMemory::InstallCallHook(0x438F90, (DWORD)(void*&)p_mRemoveBadStartNode , ASM_JMP);
    CMemory::InstallCallHook(0x4386D0, (DWORD)(void*&)p_mFindNextNodeWandering, ASM_JMP);
    CMemory::InstallCallHook(0x4382B0, (DWORD)(void*&)p_mNewGenerateCarCreationCoors, ASM_JMP);
    CMemory::InstallCallHook(0x437B10, (DWORD)(void*&)p_mGeneratePedCreationCoors, ASM_JMP);
    CMemory::InstallCallHook(0x437A40, (DWORD)(void*&)p_mTestCoorsCloseness, ASM_JMP);
    CMemory::InstallCallHook(0x4377F0, (DWORD)(void*&)p_mCalcRoadDensity, ASM_JMP);
    CMemory::InstallCallHook(0x436E40, (DWORD)(void*&)p_mFindNodeClosestToCoorsFavourDirection, ASM_JMP);
    CMemory::InstallCallHook(0x4354E0, (DWORD)(void*&)p_mTestCrossesRoad, ASM_JMP);
    CMemory::InstallCallHook(0x4356B0, (DWORD)(void*&)p_mTestForPedTrafficLight, ASM_JMP);

    CMemory::InstallCallHook(0x434EB0, (DWORD)(void*&)p_mCalculateLaneDistance, ASM_JMP);
    CMemory::InstallCallHook(0x435140, (DWORD)&CPedPath::CalculateBestRandomCoors, ASM_JMP);
    CMemory::InstallCallHook(0x4351C0, (DWORD)&CPedPath::CalculateRandomCoordinates, ASM_JMP);

    // hooks inside CAutopilot::ModifySpeed
    CMemory::InstallCallHook(0x418D48, (DWORD)HookModSpeedGetDetachedNormalXOne, ASM_JMP);
    CMemory::InstallCallHook(0x418D68, (DWORD)HookModSpeedGetDetachedYCoorOne, ASM_JMP);
    CMemory::InstallCallHook(0x418DAA, (DWORD)HookModSpeedGetDetachedNormalXTwo, ASM_JMP);
    CMemory::InstallCallHook(0x418DCB, (DWORD)HookModSpeedGetDetachedXCoorOne, ASM_JMP);
    CMemory::InstallCallHook(0x418DEF, (DWORD)HookModSpeedGetDetachedNormalYOne, ASM_JMP);
    CMemory::InstallCallHook(0x418E21, (DWORD)HookModSpeedGetDetachedYCoorTwo, ASM_JMP);
    CMemory::InstallCallHook(0x418E48, (DWORD)HookModSpeedGetDetachedXCoorTwo, ASM_JMP);
    CMemory::InstallCallHook(0x418E7C, (DWORD)HookModSpeedGetDetachedNormalYTwo, ASM_JMP);
    CMemory::InstallCallHook(0x418EB8, (DWORD)HookModSpeedGetDetachedNormalYThree, ASM_JMP);
    CMemory::InstallCallHook(0x418EE9, (DWORD)HookModSpeedGetDetachedNormalXThree, ASM_JMP);
    CMemory::InstallCallHook(0x418F15, (DWORD)HookModSpeedGetDetachedNormalYFour, ASM_JMP);
    CMemory::InstallCallHook(0x418F45, (DWORD)HookModSpeedGetDetachedNormalXFour, ASM_JMP);

    //hooks inside CCarCtrl::GenerateOneEmergencyServicesCar
    CMemory::InstallCallHook(0x41C4F1, (DWORD)HookGenEmerCarCheckVehicleType, ASM_JMP);
    CMemory::InstallCallHook(0x41C6A5, (DWORD)HookGenEmerCarGetAttachedZCoorsOne, ASM_JMP);
    CMemory::InstallPatch<CPathFind*>(0x41C4BD, pThePaths);

    //hook inside CCarCtrl::FindLinksToGoWithTheseNodes
    CMemory::InstallCallHook(0x41CC20, (DWORD)HookFindLinksToGoWithTheseNodes, ASM_JMP);

    //hooks inside CCarCtrl::JoinCarWithRoadSystemGotoCoors
    CMemory::InstallPatch<CPathFind*>(0x41CECF, pThePaths);
    CMemory::InstallPatch<CPathFind*>(0x41CF21, pThePaths);
    CMemory::InstallCallHook(0x41CF52, (DWORD)HookJoinCarWithRoadFixPathPointerSubtract, ASM_JMP);
}

void CPathFindHook::RemoveHook(){
}