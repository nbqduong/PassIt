//
// Created by duong on 8/15/24.
//

#include "Setting.h"


uint16_t MainWindowSetting::mScreenWidth{1600};
uint16_t MainWindowSetting::mScreenHeight{960};
uint16_t MainWindowSetting::mViewUnit{64};
uint16_t MainWindowSetting::mSourceUnit{64};
uint16_t MainWindowSetting::mFrame{64};
vector<OptionInfo> MainWindowSetting::mOptions{
    {"Hero", {"Basic","Simple"}},
    {"Map",{"Ice","Forest"}},
    {"WindowSize",{"Medium","Large", "FullScreen"}},
};

MainWindowSetting::MainWindowSetting()
{}

MainWindowSetting& MainWindowSetting::Instance()
{
    static MainWindowSetting mInstance;
    return mInstance;
}

void MainWindowSetting::Set(uint16_t screen_width, uint16_t screen_height, uint16_t source_unit, uint16_t frame)
{
    mScreenWidth = screen_width;
    mScreenHeight = screen_height;
    mViewUnit = mScreenWidth/MAX_X;
    mSourceUnit = source_unit;
    mFrame = frame;
}

Co Convert::WindowSize(std::string_view size)
{
    if(size.compare("Medium") == 0)
    {
        return MEDIUM_WINDOW;
    }
    else
    {
        return LARGE_WINDOW;
    }
}