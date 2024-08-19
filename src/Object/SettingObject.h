//
// Created by duong on 8/19/24.
//

#ifndef TEMPLATE_SETTINGOBJECT_H
#define TEMPLATE_SETTINGOBJECT_H


#include "SettingFactory.h"
class SettingObject:public SettingFactory
{
    SettingObject();
public:
    static SettingObject& Instance(){static SettingObject mInstance; return mInstance;}

    //Handle commands
    void HandleCommand(const UserEvent &event);
    ~SettingObject();
};


#endif //TEMPLATE_SETTINGOBJECT_H
