//
// Created by duong on 8/19/24.
//

#include "SettingObject.h"
#include "Exception.h"
#include <SDL_log.h>
#include <iostream>


SettingObject::SettingObject(): SettingFactory("Setting")
{
    RegisterOption("Hero",{"Basic","Simple"});
    RegisterOption("Map",{"Ice","Forest"});
    RegisterOption("WindowSize",{"Small","Medium","Large", "FullScreen"});
    CreateSettings();

}

void SettingObject::HandleCommand(const UserEvent &event)
{
    if(event == UserEvent::emUp || event == UserEvent::emDown)
    {
        SwitchSetting(event);
    }
    else if(event == UserEvent::emLeft || event == UserEvent::emRight)
    {
        SwitchOption(event);
    }
    else
    {
        return;
    }
}

SettingObject::~SettingObject()
{
    SDL_Log("~Setting Objects destructor");
}