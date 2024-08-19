//
// Created by duong on 8/15/24.
//

#ifndef PASSIT_SETTING_H
#define PASSIT_SETTING_H

#include "config.hpp"
#include <cstdint>
#include <string>

enum class UserEvent {
    emQuit,
    emUp,
    emDown,
    emLeft,
    emRight,
    emSpace,
    emR,
    emRepeat,
    emNone,
};


class Co{
public:
    uint16_t X{},Y{};
    Co(uint16_t x=0, uint16_t  y=0):X(x),Y(y){};
    Co(const Co& Other):X(Other.X),Y(Other.Y){};
    bool operator==(const Co& Other)const{return X == Other.X && Y==Other.Y;}
    bool operator=(const Co& Other){X = Other.X; Y=Other.Y;}
};

//class Setting
//{
//protected:
//    //    //Basic display parameters
//    static uint16_t mScreenWidth;
//    static uint16_t mScreenHeight;
//public:
//    static std::string GetFontPath(){return std::string(_materials)+"Myfont.ttf";}
//};


class MainWindowSetting
{

//    //Basic display parameters
    static uint16_t mScreenWidth;
    static uint16_t mScreenHeight;
    static uint16_t mViewUnit;
    static uint16_t mSourceUnit;
    static uint16_t mFrame;
    MainWindowSetting();
public:
    static MainWindowSetting& Instance();
    static uint16_t GetSourceonView(){return mSourceUnit/mViewUnit;};
    static uint8_t MaxX(){return uint8_t(mScreenWidth/mViewUnit);};
    static uint8_t MaxY(){return uint8_t(mScreenHeight/mViewUnit);};
    static uint16_t GetScreenPX(){return mScreenWidth;}
    static uint16_t GetScreenPY(){return mScreenHeight;}
    void Set(uint16_t screen_width, uint16_t screen_height, uint16_t view_unit = 64, uint16_t source_unit = 64, uint16_t frame = 64 );
    static std::string GetFontPath(){return std::string(_materials)+"Myfont.ttf";}
    static uint16_t GetViewUnit(){return mViewUnit;}
    static uint16_t GetFrame(){return mFrame;}
};

class Convert
{
public:
    static uint16_t toPx(uint16_t P){return P*MainWindowSetting::Instance().GetViewUnit();}
    static Co toPx(uint16_t X, uint16_t Y){return {static_cast<uint16_t >(X*MainWindowSetting::Instance().GetViewUnit()),static_cast<uint16_t >(Y*MainWindowSetting::Instance().GetViewUnit())};}

};



#endif //PASSIT_SETTING_H
