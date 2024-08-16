//
// Created by duong on 8/15/24.
//

#include "Setting.h"

uint16_t Setting::mScreenWidth{1600};
uint16_t Setting::mScreenHeight{960};
uint16_t Setting::mViewUnit{64};
uint16_t Setting::mSourceUnit{64};
uint16_t Setting::mFrame{64};


Setting::Setting()
{}

Setting Setting::Instance()
{
    static Setting mInstance;
    return mInstance;
}

void Setting::Set(uint16_t screen_width, uint16_t screen_height, uint16_t view_unit, uint16_t source_unit, uint16_t frame)
{
    mScreenWidth = screen_width;
    mScreenHeight = screen_height;
    mViewUnit = view_unit;
    mSourceUnit = source_unit;
    mFrame = frame;
}