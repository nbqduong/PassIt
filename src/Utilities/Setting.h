//
// Created by duong on 8/15/24.
//

#ifndef PASSIT_SETTING_H
#define PASSIT_SETTING_H

#include <cstdint>

class Co{
public:
    uint16_t X{},Y{};
    Co(uint16_t x=0, uint16_t  y=0):X(x),Y(y){};
    Co(const Co& Other):X(Other.X),Y(Other.Y){};
    bool operator==(const Co& Other)const{return X == Other.X && Y==Other.Y;}
    bool operator=(const Co& Other){X = Other.X; Y=Other.Y;}
};

class Setting
{

//    //Basic display parameters
    static uint16_t mScreenWidth;
    static uint16_t mScreenHeight;
    static uint16_t mViewUnit;
    static uint16_t mSourceUnit;
    static uint16_t mFrame;

    Setting();
public:
    Setting Instance();
    static uint16_t GetSourceonView(){return mSourceUnit/mViewUnit;};
    static uint8_t MaxX(){return uint8_t(mScreenWidth/mViewUnit);};
    static uint8_t MaxY(){return uint8_t(mScreenHeight/mViewUnit);};
    static uint16_t GetScreenPX(){return mScreenWidth;}
    static uint16_t GetScreenPY(){return mScreenHeight;}
    void Set(uint16_t screen_width, uint16_t screen_height, uint16_t view_unit = 64, uint16_t source_unit = 64, uint16_t frame = 64 );


};



#endif //PASSIT_SETTING_H
