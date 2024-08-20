//
// Created by duong on 8/19/24.
//

#ifndef TEMPLATE_WINDOWMANAGER_H
#define TEMPLATE_WINDOWMANAGER_H


#include "Input.h"
#include "SettingObject.h"
#include "Window.h"
#include "config.hpp"
#include <any>
using std::any;

class WindowManager:  public Windows
{
public:
    WindowManager(std::string_view windows_name, uint16_t size_PX, uint16_t size_PY, uint16_t pos_PX=0, uint16_t pos_PY=0);
    virtual void ExecuteCommand(UserEvent event) = 0;
    virtual any GetInformation(){};
};

class SettingWindow : public WindowManager
{
    SettingObject mSetting{SettingObject::Instance()};
public:
    SettingWindow();
    any GetInformation () override;
    void ExecuteCommand(UserEvent event);
};

class MainWindow : public WindowManager
{
public:
    MainWindow();
    void ExecuteCommand(UserEvent event){};
};

class PauseWindow : public WindowManager
{
public:
    PauseWindow();
    void ExecuteCommand(UserEvent event){};
};

#endif //TEMPLATE_WINDOWMANAGER_H
