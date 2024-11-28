#include "Map/Course.hpp"

typedef unsigned char byte;

void Course::GetDungeonProgress(CourseProgress *progress)
{
    progress->flags = mFlags1[0];
        /* if course is totok */

    if (mType == 3) {
        return;
    }
    progress->numKeys = (char)mNumKeys;
    progress->blueWarpOpen = mBlueWarpOpen;
    progress = NULL;
    return;
}

unk32 func_ov000_020972e4(s32 a, s32 b, s32 c);

void Course::func_ov00_0207ca28(s32 r0, unk32 r1, unk32 r2) {

}


char *Course::SetCourseName(char *src)
{
  asm (
    "ldr r12, [pc, #0x4] ;\n"
    "add r0, r0, #0xc ;\n"
    "bx r12 ;\n"
  );

  return mName;
}

void Course::func_ov00_0207ca78(unk32 param_2, unk8 param_3, unk32 param_4) {

}

bool Course::func_ov00_0207caa8(s32 param_2, unk32 *param_3, unk8 *param_4) {

}

unk32 Course::func_ov00_0207cb30(s32 param_2) {

}


void Course::FindMapGridPos(Vec2b *pos, Course *param_2, u32 map)
{
  byte bVar1;
  int y;
  Course *course_unk20;
  int x;
  
  x = 0;
  course_unk20 = param_2;
  do {
    y = 0;
    do {
      if (map == (byte)course_unk20->mMapGrid[0][y]) {
        pos->x = (byte)x;
        pos->y = (byte)y;
        return;
      }
      y = y + 1;
    } while (y < 10);
    x = x + 1;
    course_unk20 = (Course *)((int)&course_unk20->mUnk_008 + 2);
  } while (x < 10);
  bVar1 = (param_2->mCurrMapPos).y;
  pos->x = (param_2->mCurrMapPos).x;
  pos->y = bVar1;
  return;
}

Vec3p *Course::FindMapCenter(unk32 map)
{
  MapData *data;
  data = FindMapData(map);
  return &data->mCenter;
}

void Course::func_ov00_0207cbe8(s32 param_2) {

}

unk8 Course::func_ov00_0207cc24(s32 param_2) {

}

unk32 Course::FindMapData_Unk_08(unk32 map) {
  MapData *iVar1;
  u32 uVar1;
  
  iVar1 = FindMapData(map);
  if (iVar1 == (MapData *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = iVar1->mUnk_08;
  }
  return uVar1;
}

void Course::GetMCSFilePath(char* buf, s32 fileIndex, unk32 fileType) {
  // switch(fileType) {
  // case 0:
  // default:
  //                   /* Zelda Course Arrangement Binary (ZCAB) */
  //   sprintf(buf,PTR_s_%s:arrange/%s.zab_overlay_d_0__020e20d8_overlay_d_0__0207cd70,
  //           *(undefined4 *)
  //            PTR_PTR_s_MCS_overlay_d_0__020e2520_overlay_d_0__020e2508_overlay_d_0__0207cd58);
  //   return;
  // case 1:
  //   break;
  // case 2:
  //                   /* NPC Type ZOB */
  //   if (fileIndex != 0) {
  //     sprintf(buf,PTR_s_%s:objlist/npctype_%d.zob_overlay_d_0__020e20a4_overlay_d_0__0207cd68,
  //             *(undefined4 *)
  //              PTR_PTR_s_MCS_overlay_d_0__020e2520_overlay_d_0__020e2508_overlay_d_0__0207cd58);
  //     return;
  //   }
  //   sprintf(buf,PTR_s_%s:objlist/npctype.zob_overlay_d_0__020e208c_overlay_d_0__0207cd64,
  //           *(undefined4 *)
  //            PTR_PTR_s_MCS_overlay_d_0__020e2520_overlay_d_0__020e2508_overlay_d_0__0207cd58);
  //   return;
  // case 3:
  //                   /* Map textures */
  //   sprintf(buf,PTR_s_%s:tex/mapModel.nsbtx_overlay_d_0__020e20c0_overlay_d_0__0207cd6c,
  //           *(undefined4 *)
  //            PTR_PTR_s_MCS_overlay_d_0__020e2520_overlay_d_0__020e2508_overlay_d_0__0207cd58);
  //   return;
  // }
  // if (fileIndex != 0) {
  //   sprintf(buf,PTR_s_%s:objlist/motype_%d.zob_overlay_d_0__020e2070_overlay_d_0__0207cd60,
  //           *(undefined4 *)
  //            PTR_PTR_s_MCS_overlay_d_0__020e2520_overlay_d_0__020e2508_overlay_d_0__0207cd58);
  //   return;
  // }
  //                   /* Monster Type ZOB */
  // sprintf(buf,PTR_s_%s:objlist/motype.zob_overlay_d_0__020e2058_overlay_d_0__0207cd5c,
  //         *(undefined4 *)
  //          PTR_PTR_s_MCS_overlay_d_0__020e2520_overlay_d_0__020e2508_overlay_d_0__0207cd58);
  // return;
}

void Course::GetMRCFilePath(unk32 param_2, char* buf, unk32 fileType) {
  // switch(param_4) {
  // case 0:
  //   break;
  // case 1:
  //   sprintf(buf,PTR_s_%s:objlist/motype.zob_overlay_d_0__020e20ec_overlay_d_0__0207ce0c,
  //           *(undefined4 *)
  //            PTR_PTR_s_MRC_overlay_d_0__020e2524_overlay_d_0__020e250c_overlay_d_0__0207ce08);
  //   return;
  // case 2:
  //   sprintf(buf,PTR_s_%s:objlist/npctype.zob_overlay_d_0__020e2104_overlay_d_0__0207ce10,
  //           *(undefined4 *)
  //            PTR_PTR_s_MRC_overlay_d_0__020e2524_overlay_d_0__020e250c_overlay_d_0__0207ce08);
  //   return;
  // case 3:
  //   sprintf(buf,PTR_s_%s:tex/mapModel.nsbtx_overlay_d_0__020e211c_overlay_d_0__0207ce14,
  //           *(undefined4 *)
  //            PTR_PTR_s_MRC_overlay_d_0__020e2524_overlay_d_0__020e250c_overlay_d_0__0207ce08);
  //   return;
  // }
  // FUN_overlay_d_0__0209d71c(*(undefined4 *)PTR_DWORD_overlay_d_0__0207ce18);
  // sprintf(buf,PTR_s_%s:arrange/%s.zab_overlay_d_0__020e2134_overlay_d_0__0207ce1c,
  //         *(undefined4 *)
  //          PTR_PTR_s_MRC_overlay_d_0__020e2524_overlay_d_0__020e250c_overlay_d_0__0207ce08);
  // return;
}

void Course::func_ov00_0207ce20(unk32 param_2, unk32 param_3, char *param_4, unk32 param_5) {

}

void Course::func_ov00_0207ce4c(s32 param_2, s32 param_3, unk32 param_4, char *param_5, unk32 param_6) {

}

bool Course::func_ov00_0207d404(s32 param_2, unk32 param_3, unk32 param_4) {

}

bool Course::IsCurrentMapInMainGrid() {
  return IsInMainGrid((u8)mCurrMapPos.x, (u8)mCurrMapPos.y);
}

bool Course::IsInMainGrid(s32 x, s32 y) {
  if (mUnk_25c == 0) {
    return true;
  }

  u32 uVar1 = (u8)(mMainGrid).x;
  if (((((int)uVar1 <= x) && (x < (int)(uVar1 + (u8)mMainGridSize.x))) &&
      (uVar1 = (u8)(mMainGrid).y, (int)uVar1 <= y)) &&
     (y < (int)(uVar1 + (u8)mMainGridSize.y))) {
    return true;
  }
  return false;
}

bool Course::IsMapInMainGrid(u32 map) {
  bool bVar1;
  Vec2b local_10;

  FindMapGridPos(&local_10,this,map);
  bVar1 = IsInMainGrid((u8)local_10.x,(u8)local_10.y);
  return bVar1;
}

bool Course::GetMapScreenPos(s32 map, s32 *x, s32 *y) {

  byte bVar1;
  bool inMainGrid;
  int xPixelsPerMap;
  int yPixelsPerMap;
  byte minGridDim;
  Vec2b local_18;
  
  if (map == 0xff) {
    return false;
  }
  s32 *_local_18 = y;
  FindMapGridPos(&local_18,this,map);
  inMainGrid = IsInMainGrid((s32)_local_18 & 0xff,(s32)_local_18 >> 8 & 0xff);
  if (inMainGrid) {
    minGridDim = mMainGridSize.x;
    bVar1 = mMainGridSize.y;
    if (minGridDim < bVar1) {
      minGridDim = bVar1;
    }
    *x = xPixelsPerMap * (((u32)_local_18 & 0xff) - (u32)(this->mMainGrid).x) +
         this->mScreenMapOffsetX;
    *y = yPixelsPerMap * (((u32)_local_18 >> 8 & 0xff) - (u32)(this->mMainGrid).y) +
         this->mScreenMapOffsetY;
    return true;
  }
  return false;
}

u32 Course::GetScreenMapCellSizeX() {
  u32 r0 = (u8)mMainGridSize.x;
  u32 r1 = (u8)mMainGridSize.y;

  if (r1 > r0) {
    r0 = r1;
  }

  r1 <<= 0xC;
  //r0 = 0x100000;

  return r1 + r0;
}

u32 Course::GetScreenMapCellSizeY() {
  u32 uVar1;
  u32 uVar2;
  
  uVar2 = mMainGridSize.y;
  uVar1 = mMainGridSize.x;
  if (uVar2 < uVar1) {
    uVar2 = uVar1;
  }
  //uVar2 = CoDivide64By32(0xc0000,uVar2 << 0xc);
  //uVar2 = CoDivide64By32(uVar2,0x30000);
  return uVar2;
}

unk32 Course::Get_Unk_c8_00() {
  asm(
    "ldr r0, [r0, #0xc8] ;\n" 
    "ldr r0, [r0, #0x0] ;\n"
  );
}

unk32 Course::Get_Unk_c8_04() {
  return mUnk_0c8->mUnk_04;
}

bool Course::IsAdjacentMapOnMainGrid(unk32 dir) {
  bool bVar1;
  u32 x;
  u32 y;
  
  x = (u8)(mCurrMapPos).x;
  y = (u8)(mCurrMapPos).y;

  switch(dir) {
  case 0:
    x = x + 1;
    break;
  case 1:
    x = x - 1;
    break;
  case 2:
    y = y + 1;
    break;
  case 3:
    y = y - 1;
  }
  bVar1 = IsInMainGrid(x,y);
  if (!bVar1) {
    return false;
  }
  bVar1 = HasGridMap(x,y);
  return bVar1;
}

bool Course::HasGridMap(s32 r1, s32 r2) {
  if ((0 > r1 || 0 > r2) || (r1 >= 0xa || r2 >= 0xa)) {
    return false;
  }
  return (u8)mMapGrid[r1][r2] != 0xff;
}

unk8 Course::GetAdjacentMap(unk32 dir) {

  if (IsAdjacentMapOnMainGrid(dir)) {
    u32 x = GetAdjacentMapX(dir);
    u32 y = GetAdjacentMapY(dir);
    
    return mMapGrid[x][y];
  }
  return 0xff;
}

u32 Course::GetAdjacentMapX(s32 ir) {

  u32 uVar1 = (u8)mCurrMapPos.x;
  if (ir != 0) {
    if (ir == 1) {
      uVar1 = uVar1 - 1;
    }
    return uVar1;
  }
  return uVar1 + 1;
}

u32 Course::GetAdjacentMapY(s32 dir) {

  u32 y = (u8)mCurrMapPos.y;
  if (dir != 2) {
    if (dir == 3) {
      y = y - 1;
    }
    return y;
  }
  return y + 1;
}

u16 Course::FindCurrentMapData_Unk_04() {
  return FindCurrentMapData() -> mUnk_04;
}


u32 Course::FindMapData_Unk_04(unk32 param_2) {

  MapData* mapData = FindMapData(param_2);
  if (mapData == NULL) {
    return 0xffff;
  } else {
    return mapData -> mUnk_04;
  }
}

unk32 Course::FindMapData_Unk_0c(unk32 map) {
  MapData *iVar1;
  u32 uVar1;
  
  iVar1 = FindMapData(map);
  if (iVar1 == (MapData *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = iVar1->mUnk_0c;
  }
  return uVar1;
}

void Course::func_ov00_0207d7bc() {

}


void Course::SetFlag0(u32 index, bool value) {
  if (value) {
    mFlags0[index >> 5] = mFlags0[index >> 5] | 1 << (index & 0x1f);
    return;
  }
  mFlags0[index >> 5] = mFlags0[index >> 5] & ~(1 << (index & 0x1f));
  return;
}

bool Course::GetFlag0(u32 index) {
    return (mFlags0[index >> 5] & 1 << (index & 0x1f)) != 0;
}

void Course::SetFlag1(u32 index, bool value) {
  if (value) {
    mFlags1[index >> 5] = mFlags1[index >> 5] | 1 << (index & 0x1f);
    return;
  }
  mFlags1[index >> 5] = mFlags1[index >> 5] & ~(1 << (index & 0x1f));
  return;
}
bool Course::SetFlag1(u32 index) {
    return (mFlags1[index >> 5] & 1 << (index & 0x1f)) != 0;
}

void Course::SetMapDataFlag0(unk32 index, bool value) {
  FindCurrentMapData() -> SetFlag0(index,value);
}

bool Course::GetMapDataFlag0(unk32 index) {
  return FindCurrentMapData() -> GetFlag0(index);
}

void Course::SetMapDataFlag1(unk32 index, bool value) {
  FindCurrentMapData() -> SetFlag1(index,value);
}

bool Course::GetMapDataFlag1(unk32 index) {
  return FindCurrentMapData() -> GetFlag1(index);
}

void Course::SetMapDataFlag2(unk32 index, bool value) {
  FindCurrentMapData() -> SetFlag2(index,value);
}

bool Course::GetMapDataFlag2(unk32 index) {
  return FindCurrentMapData() -> GetFlag2(index);
}

void Course::SetMapDataFlag3(unk32 index, bool value) {
  FindCurrentMapData() -> SetFlag3(index,value);
}

bool Course::GetMapDataFlag3(unk32 index) {
  return FindCurrentMapData() -> GetFlag3(index);
}

void Course::SetMapDataFlag4(unk32 index, unk32 value) {
  FindCurrentMapData() -> SetFlag4(index,value);
}

bool Course::GetMapDataFlag4(unk32 index) {
  return FindCurrentMapData() -> GetFlag4(index);
}

MapData *Course::FindMapData(u32 map) {
  MapData *pMVar1;
  int i;
  
  i = 0;
  if (mNumMaps != 0) {
    do {
      pMVar1 = mMapData[i];
      if ((pMVar1 != NULL) && (map == pMVar1->mMap)) {
        return pMVar1;
      }
      i = i + 1;
    } while (i < (int)(unsigned int)mNumMaps);
  }
  return NULL;
}

MapData *Course::FindCurrentMapData() {
  return FindMapData(mMapGrid[(mCurrMapPos).x][(mCurrMapPos).y]);
}

