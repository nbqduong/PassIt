//
// Created by duong on 8/15/24.
//

#include "Setting.h"

uint16_t MainWindowSetting::mScreenWidth{1600};
uint16_t MainWindowSetting::mScreenHeight{960};
uint16_t MainWindowSetting::mViewUnit{64};
uint16_t MainWindowSetting::mSourceUnit{64};
uint16_t MainWindowSetting::mFrame{64};


MainWindowSetting::MainWindowSetting()
{}

MainWindowSetting& MainWindowSetting::Instance()
{
    static MainWindowSetting mInstance;
    return mInstance;
}

void MainWindowSetting::Set(uint16_t screen_width, uint16_t screen_height, uint16_t view_unit, uint16_t source_unit, uint16_t frame)
{
    mScreenWidth = screen_width;
    mScreenHeight = screen_height;
    mViewUnit = view_unit;
    mSourceUnit = source_unit;
    mFrame = frame;
}