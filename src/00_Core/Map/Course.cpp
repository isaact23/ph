#include "Map/Course.hpp"

void Course::GetDungeonProgress(CourseProgress *param_2)
{
    param_2->flags = mFlags1[0];
        /* if course is totok */

    if (mType == 3) {
        return;
    }
    param_2->numKeys = (char)mNumKeys;
    param_2->blueWarpOpen = mBlueWarpOpen;
    return;
}


void Course::func_ov00_0207ca28(s32 param_2, unk32 param_3, unk32 param_4) {}

char *Course::SetCourseName(char *src)
{
    char *pcVar1;
  
        /* WARNING: Could not recover jumptable at 0x0207ca70. Too many branches */
        /* WARNING: Treating indirect jump as call */
    pcVar1 = (char *)(*(code *)PTR_strcpy_overlay_d_0__0207ca74)(mName);
    return pcVar1;
}

void Course::func_ov00_0207ca78(unk32 param_2, unk8 param_3, unk32 param_4) {}
bool Course::func_ov00_0207caa8(s32 param_2, unk32 *param_3, unk8 *param_4) {}
unk32 Course::func_ov00_0207cb30(s32 param_2) {}

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
        course_unk20 = (Course *)((int)&course_unk20->field2_0x8 + 2);
    } while (x < 10);
    bVar1 = (param_2->mCurrMapPos).y;
    pos->x = (param_2->mCurrMapPos).x;
    pos->y = bVar1;
    return;
}

Vec3p *Course::FindMapCenter(unk32 map)
{
    MapData *iVar1;
    
    iVar1 = FindMapData(*this,map);
    return &iVar1->mCenter;
}

void Course::func_ov00_0207cbe8(s32 param_2) {}
unk8 Course::func_ov00_0207cc24(s32 param_2) {}
unk32 Course::FindMapData_Unk_08(unk32 map) {}
void Course::GetMCSFilePath(unk32 buf, s32 fileIndex, unk32 fileType) {}
void Course::GetMRCFilePath(unk32 param_2, unk32 buf, unk32 param_4) {}
void Course::func_ov00_0207ce20(unk32 param_2, unk32 param_3, char *param_4, unk32 param_5) {}
void Course::func_ov00_0207ce4c(s32 param_2, s32 param_3, unk32 param_4, char *param_5, unk32 param_6) {}
bool Course::func_ov00_0207d404(s32 param_2, unk32 param_3, unk32 param_4) {}
bool Course::IsCurrentMapInMainGrid() {}
bool Course::IsInMainGrid(s32 x, s32 y) {}
bool Course::IsMapInMainGrid(u32 map) {}
bool Course::GetMapScreenPos(s32 map, s32 *x, s32 *y) {}
u32 Course::GetScreenMapCellSizeX() {}
u32 Course::GetScreenMapCellSizeY() {}
unk32 Course::Get_Unk_c8_00() {}
unk32 Course::Get_Unk_c8_04() {}
bool Course::IsAdjacentMapOnMainGrid(unk32 dir) {}
bool Course::HasGridMap(s32 x, s32 y) {}
unk8 Course::GetAdjacentMap(unk32 dir) {}
u32 Course::GetAdjacentMapX(s32 ir) {}
u32 Course::GetAdjacentMapY(s32 dir) {}
u16 Course::FindCurrentMapData_Unk_04() {}
u32 Course::FindMapData_Unk_04(unk32 param_2) {}
unk32 Course::FindMapData_Unk_0c(unk32 map) {}
void Course::func_ov00_0207d7bc() {}
void Course::SetFlag0(u32 index, bool value) {}
bool Course::GetFlag0(u32 index) {}
void Course::SetFlag1(u32 index, bool value) {}
bool Course::SetFlag1(u32 index) {}
void Course::SetMapDataFlag0(unk32 index, bool value) {}
bool Course::GetMapDataFlag0(unk32 param_2) {}
void Course::SetMapDataFlag1(unk32 param_2, bool param_3) {}
bool Course::GetMapDataFlag1(unk32 param_2) {}
void Course::SetMapDataFlag2(unk32 param_2, bool param_3) {}
bool Course::GetMapDataFlag2(unk32 param_2) {}
void Course::SetMapDataFlag3(unk32 param_2, bool param_3) {}
bool Course::GetMapDataFlag3(unk32 param_2) {}
void Course::SetMapDataFlag4(unk32 param_2, unk32 param_3) {}
bool Course::GetMapDataFlag4(unk32 param_2) {}
MapData *Course::FindMapData(u32 map) {}
MapData *Course::FindCurrentMapData() {}
