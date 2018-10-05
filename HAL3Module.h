void __fastcall CamX::HAL3Module::HAL3Module(CamX::HAL3Module *this)
{
  CamX::HAL3Module *v1; // r4@1
  const CHAR *v2; // r0@1
  const CHAR *v3; // r0@1
  const CHAR *v4; // r0@1
  const CHAR *v5; // r0@1
  const CHAR *v6; // r0@1
  CamX::HwEnvironment *v7; // r0@1
  signed int v15; // r0@1
  const CHAR *v17; // r0@5
  int v18; // r0@6
  int v19; // r6@6
  const CHAR *v20; // r0@9
  const CHAR *v21; // r0@11
  VOID *v22; // r0@12
  const CHAR *v23; // r0@14
  void (__fastcall *v24)(CamX::CHIAppCallbacks *); // r1@15
  const CHAR *v25; // r0@28
  const CHAR *v26; // r0@29
  int v27; // r3@29
  const CHAR *v28; // r0@30
  int v29; // r2@30
  int v30; // r3@30
  INT (*v31)(UINT32 *, UINT32 *); // r2@31
  UINT32 *v32; // r0@31
  CHAR pFileNames; // [sp+10h] [bp-418h]@6
  int v34; // [sp+410h] [bp-18h]@1

  v1 = this;
  v34 = _stack_chk_guard;
  v2 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
  CamX::Log::LogSystem(
    0,
    (const CHAR *)"[DEBUG]%s %s:338 %s() ***************************************************",
    (int)"[HAL    ]",
    (int)v2,
    "HAL3Module");
  v3 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
  CamX::Log::LogSystem(
    0,
    (const CHAR *)"[DEBUG]%s %s:339 %s() SHA1:     %s",
    (int)"[HAL    ]",
    (int)v3,
    "HAL3Module",
    "fb0924cbcaa20cd96eeb85b2756c2347e8b57232");
  v4 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
  CamX::Log::LogSystem(
    0,
    (const CHAR *)"[DEBUG]%s %s:340 %s() COMMITID: %s",
    (int)"[HAL    ]",
    (int)v4,
    "HAL3Module",
    "I4715b8fe0fbc22073f0bd712984c3ccf1af76646");
  v5 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
  CamX::Log::LogSystem(
    0,
    (const CHAR *)"[DEBUG]%s %s:341 %s() BUILD TS: %s",
    (int)"[HAL    ]",
    (int)v5,
    "HAL3Module",
    "2/11/2018 15:59:43");
  v6 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
  CamX::Log::LogSystem(
    0,
    (const CHAR *)"[DEBUG]%s %s:342 %s() ***************************************************",
    (int)"[HAL    ]",
    (int)v6,
    "HAL3Module");
  v7 = CamX::HwEnvironment::GetInstance();
  __asm { VMOV.I32        Q8, #0 }
  _R5 = &v1->m_ChiAppCallbacks.CHIGetNumCameras;
  v1->m_pStaticSettings = v7->m_pSettingsManager->m_pStaticSettings;
  _R0 = (int)&v1->m_ChiAppCallbacks.CHIRemapCameraId;
  __asm { VST1.8          {D16-D17}, [R0] }
  _R0 = (int)&v1->m_ChiAppCallbacks.CHITeardownOverrideSession;
  __asm { VST1.8          {D16-D17}, [R0] }
  v15 = 64;
  __asm
  {
    VST1.8          {D16-D17}, [R5]
    VMOV.I32        Q8, #1
  }
  do
  {
    _R1 = (int)v1 + v15;
    v15 += 16;
    __asm { VST1.32         {D16-D17}, [R1] }
  }
  while ( !_ZF );
  v1->m_pMetadata = 0;
  if ( dword_1B9B1C & 0x80 )
  {
    v17 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
    CamX::Log::LogSystem(
      2u,
      (const CHAR *)"[ WARN]%s %s:362 %s() Searching for Chi Override module in folder: %s",
      (int)"[HAL    ]",
      (int)v17,
      "HAL3Module",
      &"/vendor/lib/hw");
  }
  v18 = CamX::OsUtils::GetFilesFromPath(
          (const CHAR *)&"/vendor/lib/hw",
          0x400u,
          &pFileNames,
          (const CHAR *)&dword_36F38,
          (const CHAR *)&dword_36F3C,
          (const CHAR *)&dword_36F38,
          (const CHAR *)&"so");
  v19 = v18;
  if ( v18 == 1 )
  {
    if ( dword_1B9B1C & 0x80 )
    {
      v21 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
      CamX::Log::LogSystem(
        2u,
        (const CHAR *)"[ WARN]%s %s:380 %s() 1 CHI Module library found - %s and trying to open it",
        (int)"[HAL    ]",
        (int)v21,
        "HAL3Module",
        &pFileNames);
    }
    v22 = CamX::OsUtils::LibMap(&pFileNames);
    v1->m_hChiOverrideModuleHandle = v22;
    if ( v22 )
    {
      if ( dword_1B9B1C & 0x80 )
      {
        v23 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
        CamX::Log::LogSystem(
          2u,
          (const CHAR *)"[ WARN]%s %s:386 %s() CHI Module library successfully opened",
          (int)"[HAL    ]",
          (int)v23,
          "HAL3Module");
        v22 = v1->m_hChiOverrideModuleHandle;
      }
      v24 = (void (__fastcall *)(CamX::CHIAppCallbacks *))CamX::OsUtils::LibGetAddr(
                                                            v22,
                                                            (const CHAR *)"chi_hal_override_entry");
      if ( v24 )
      {
        v24(&v1->m_ChiAppCallbacks);
        if ( *_R5 )
        {
          if ( v1->m_ChiAppCallbacks.CHIModifySettings
            && v1->m_ChiAppCallbacks.CHIRemapCameraId
            && v1->m_ChiAppCallbacks.CHIExtendClose
            && v1->m_ChiAppCallbacks.CHIExtendOpen
            && v1->m_ChiAppCallbacks.CHITeardownOverrideSession
            && v1->m_ChiAppCallbacks.CHIOverrideFlush
            && v1->m_ChiAppCallbacks.CHIOverrideProcessRequest
            && v1->m_ChiAppCallbacks.CHIInitializeOverrideSession
            && v1->m_ChiAppCallbacks.CHIFinalizeOverrideSession
            && v1->m_ChiAppCallbacks.CHIGetCameraInfo
            && dword_1B9B1C & 0x80 )
          {
            v25 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
            CamX::Log::LogSystem(
              2u,
              (const CHAR *)"[ WARN]%s %s:420 %s() CHI Module library function pointers exchanged",
              (int)"[HAL    ]",
              (int)v25,
              "HAL3Module");
          }
        }
      }
    }
    else
    {
      v28 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
      CamX::Log::LogSystem(
        1u,
        (const CHAR *)"[ERROR]%s %s:426 %s() Couldn't open CHI Module lib. All usecases will go thru HAL implementation",
        (int)"[HAL    ]",
        (int)v28,
        "HAL3Module");
      CamX::TraceMessageF(
        0xFFFFFFFF,
        (const CHAR *)"[ERROR]Couldn't open CHI Module lib. All usecases will go thru HAL implementation",
        v29,
        v30);
    }
  }
  else if ( v18 )
  {
    v26 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
    CamX::Log::LogSystem(
      1u,
      (const CHAR *)"[ERROR]%s %s:433 %s() Cannot have more than one CHI override module present",
      (int)"[HAL    ]",
      (int)v26,
      "HAL3Module",
      v19);
    CamX::TraceMessageF(
      0xFFFFFFFF,
      (const CHAR *)"[ERROR]Cannot have more than one CHI override module present",
      v19,
      v27);
  }
  else if ( dword_1B9B24 & 0x80 )
  {
    v20 = CamX::Log::GetFileName((const CHAR *)"/home/CORPUSERS/22714432/sdk/sdk_275/camx/src/core/hal/camxhal3module.cpp");
    CamX::Log::LogSystem(
      4u,
      (const CHAR *)"[ INFO]%s %s:374 %s() FATAL: No CHI Module library found in %s - Cannot proceed",
      (int)"[HAL    ]",
      (int)v20,
      "HAL3Module",
      &"/vendor/lib/hw");
  }
  v31 = v1->m_ChiAppCallbacks.CHIGetNumCameras;
  v32 = &v1->m_numFwCameras;
  if ( v31 )
    ((void (__fastcall *)(UINT32 *, UINT32 *))v31)(v32, &v1->m_numLogicalCameras);
  else
    *v32 = 0;
  if ( _stack_chk_guard != v34 )
    _stack_chk_fail(_stack_chk_guard - v34);
}


void __fastcall CamX::HAL3Module::~HAL3Module(CamX::HAL3Module *this)
{
  CamX::HAL3Module *v1; // r4@1
  VOID *v2; // r0@1

  v1 = this;
  v2 = this->m_hChiOverrideModuleHandle;
  if ( v2 )
  {
    CamX::OsUtils::LibUnmap(v2);
    v1->m_hChiOverrideModuleHandle = 0;
  }
}

//----- (00036FDC) --------------------------------------------------------
UINT32 __fastcall CamX::HAL3Module::GetNumCameras(const CamX::HAL3Module *this)
{
  return this->m_numFwCameras;
}

//----- (00036FE2) --------------------------------------------------------
CamxResult __fastcall CamX::HAL3Module::GetCameraInfo(const CamX::HAL3Module *this, UINT32 logicalCameraId, CamX::CameraInfo *pCameraInfo)
{
  CamxResult (*v3)(UINT32, CamX::CameraInfo *); // r3@1
  CamxResult result; // r0@2

  v3 = this->m_ChiAppCallbacks.CHIGetCameraInfo;
  if ( v3 )
    result = ((int (__fastcall *)(UINT32, CamX::CameraInfo *))v3)(logicalCameraId, pCameraInfo);
  else
    result = 1;
  return result;
}

//----- (00036FF2) --------------------------------------------------------
const CamX::StaticSettings *__fastcall CamX::HAL3Module::GetStaticSettings(CamX::HAL3Module *this)
{
  return this->m_pStaticSettings;
}