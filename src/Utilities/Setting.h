//
// Created by duong on 8/15/24.
//

#ifndef PASSIT_SETTING_H
#define PASSIT_SETTING_H

#include "config.hpp"
#include <cstdint>
#include <string>
#include<vector>

/*-----------------GENERAL DEFINE-------------------------------*/
#define MEDIUM_WINDOW   {960,540}
#define LARGE_WINDOW    {1920,1080}
#define MAX_X           30
#define MAX_Y           16

using std::string;
using std::vector;
using std::string_view;



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

struct OptionInfo{
    int current{0},max;
    string name;
    vector<string> options;
    OptionInfo()=default;
    OptionInfo(const string _name, const vector<string> &_option):name{_name}, options{_option}{max = static_cast<int>(options.size());}
    OptionInfo& operator = (const OptionInfo& other){
        name = other.name;
        max = other.max;
        current = other.current;
        options = other.options;
        return *this;
    };

    void Switch(const UserEvent &direction){
        if(direction == UserEvent::emLeft)
        {
            current =  --current >= 0 ? current : max-1;
        }
        else
        {
            current =  ++current < max ? current : 0;
        }
    }

    string Get(){return options.at(current);}
};


class MainWindowSetting
{

//    //Basic display parameters
    static uint16_t mScreenWidth;
    static uint16_t mScreenHeight;
    static uint16_t mViewUnit;
    static uint16_t mSourceUnit;
    static uint16_t mFrame;
    static vector<OptionInfo> mOptions;
    MainWindowSetting();
public:
    static MainWindowSetting& Instance();
    static uint16_t GetSourceonView(){return mSourceUnit/mViewUnit;}
    static uint16_t GetScreenPX(){return mScreenWidth;}
    static uint16_t GetScreenPY(){return mScreenHeight;}
    void Set(uint16_t screen_width, uint16_t screen_height, uint16_t source_unit = 64, uint16_t frame = 64 );
    static std::string GetFontPath(){return std::string(_materials)+"Myfont.ttf";}
    static uint16_t GetViewUnit(){return mViewUnit;}
    static uint16_t GetSourceUnit(){return mSourceUnit;}
    static uint16_t GetFrame(){return mFrame;}
    static vector<OptionInfo> GetOptions(){return mOptions;}
};

class Convert
{
public:
    static uint16_t toPx(uint16_t P){return P*MainWindowSetting::Instance().GetViewUnit();}
    static Co toPx(uint16_t X, uint16_t Y){return {static_cast<uint16_t >(X*MainWindowSetting::Instance().GetViewUnit()),static_cast<uint16_t >(Y*MainWindowSetting::Instance().GetViewUnit())};}
    static Co toPx(Co c){return {static_cast<uint16_t >(c.X*MainWindowSetting::Instance().GetViewUnit()),static_cast<uint16_t >(c.Y*MainWindowSetting::Instance().GetViewUnit())};}
    static Co toCx(Co p){return {static_cast<uint16_t>(p.X/MainWindowSetting::GetViewUnit()),static_cast<uint16_t>(p.Y/MainWindowSetting::GetViewUnit())};}
    static Co WindowSize(string_view size);
    static const string Asset(const string file){return (std::string(_materials)+file+".png");}
};



#endif //PASSIT_SETTING_H
