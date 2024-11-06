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


void Course::func_ov00_0207ca28(s32 param_2, unk32 param_3, unk32 param_4) {

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

}

void Course::GetMCSFilePath(unk32 buf, s32 fileIndex, unk32 fileType) {

}

void Course::GetMRCFilePath(unk32 param_2, unk32 buf, unk32 param_4) {

}

void Course::func_ov00_0207ce20(unk32 param_2, unk32 param_3, char *param_4, unk32 param_5) {

}

void Course::func_ov00_0207ce4c(s32 param_2, s32 param_3, unk32 param_4, char *param_5, unk32 param_6) {

}

bool Course::func_ov00_0207d404(s32 param_2, unk32 param_3, unk32 param_4) {

}

bool Course::IsCurrentMapInMainGrid() {

}

bool Course::IsInMainGrid(s32 x, s32 y) {
  u32 uVar1;
  
  if (mType == false) {
    return true;
  }
  uVar1 = (u32)(mMainGrid).x;
  if (((((int)uVar1 <= x) && (x < (int)(uVar1 + (mMainGridSize).x))) &&
      (uVar1 = (u32)(mMainGrid).y, (int)uVar1 <= y)) &&
     (y < (int)(uVar1 + (mMainGridSize).y))) {
    return true;
  }
  return false;
}

bool Course::IsMapInMainGrid(u32 map) {

}

bool Course::GetMapScreenPos(s32 map, s32 *x, s32 *y) {

}

u32 Course::GetScreenMapCellSizeX() {

}

u32 Course::GetScreenMapCellSizeY() {

}

unk32 Course::Get_Unk_c8_00() {

}

unk32 Course::Get_Unk_c8_04() {

}

bool Course::IsAdjacentMapOnMainGrid(unk32 dir) {
  bool bVar1;
  u32 x;
  u32 y;
  
  x = (u32)(mCurrMapPos).x;
  y = (u32)(mCurrMapPos).y;
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

bool Course::HasGridMap(s32 x, s32 y) {
  /*int iVar1;
  bool bVar2;
  
  if (-1 < x && -1 < y) {
    bVar2 = SBORROW4(x,10);
    iVar1 = x + -10;
    if (x < 10) {
      bVar2 = SBORROW4(y,10);
      iVar1 = y + -10;
    }
    if (iVar1 < 0 != bVar2) {
      return mMapGrid[x][y] != -1;
    }
  }
  return false;*/
}

unk8 Course::GetAdjacentMap(unk32 dir) {
  bool bVar1;
  u32 y;
  u32 x;
  
  bVar1 = IsAdjacentMapOnMainGrid(dir);
  if (bVar1) {
    y = GetAdjacentMapY(dir);
    x = GetAdjacentMapX(dir);
    return mMapGrid[x][y];
  }
  return 0xff;
}

u32 Course::GetAdjacentMapX(s32 ir) {

}

u32 Course::GetAdjacentMapY(s32 dir) {

}

u16 Course::FindCurrentMapData_Unk_04() {

}


u32 Course::FindMapData_Unk_04(unk32 param_2) {

}

unk32 Course::FindMapData_Unk_0c(unk32 map) {

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

}

bool Course::GetMapDataFlag0(unk32 param_2) {

}

void Course::SetMapDataFlag1(unk32 param_2, bool param_3) {

}

bool Course::GetMapDataFlag1(unk32 param_2) {

}

void Course::SetMapDataFlag2(unk32 param_2, bool param_3) {

}

bool Course::GetMapDataFlag2(unk32 param_2) {

}

void Course::SetMapDataFlag3(unk32 param_2, bool param_3) {

}

bool Course::GetMapDataFlag3(unk32 param_2) {

}

void Course::SetMapDataFlag4(unk32 param_2, unk32 param_3) {

}

bool Course::GetMapDataFlag4(unk32 param_2) {

}


MapData *Course::FindMapData(u32 map) {
  MapData *pMVar1;
  int i;
  
  i = 0;
  if (mNumMaps != 0) {
    do {
      pMVar1 = mMapData[i];
      if ((pMVar1 != (MapData *)0x0) && (map == pMVar1->mMap)) {
        return pMVar1;
      }
      i = i + 1;
    } while (i < (int)(unsigned int)mNumMaps);
  }
  return (MapData *)0x0;
}

MapData *Course::FindCurrentMapData() {
  return FindMapData(mMapGrid[(mCurrMapPos).x][(mCurrMapPos).y]);
}

