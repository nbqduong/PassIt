//
// Created by duong on 8/19/24.
//

#ifndef TEMPLATE_WINDOWMANAGER_H
#define TEMPLATE_WINDOWMANAGER_H


#include "Input.h"
#include "MovementManager.h"
#include "ObjectFactory.h"
#include "SettingObject.h"
#include "Window.h"
#include "config.hpp"
#include <any>
using std::any;
using std::string;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;
class WindowManager
{

protected:
    std::shared_ptr<Windows> mWindow;
public:
    WindowManager(){};
    WindowManager(std::string_view windows_name, uint16_t size_PX, uint16_t size_PY, uint16_t pos_PX=0, uint16_t pos_PY=0);
    virtual void ExecuteCommand(UserEvent event) = 0;
    virtual any GetInformation(){};
    string GetName(){return string(mWindow->GetName());}
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
    shared_ptr<ObjectFactory> mObjects;
    unique_ptr<MovementManager> mMove;

public:
    MainWindow(vector<OptionInfo> info);
    void ExecuteCommand(UserEvent event);
};

class PauseWindow : public WindowManager
{
public:
    PauseWindow();
    void ExecuteCommand(UserEvent event){};
};

#endif //TEMPLATE_WINDOWMANAGER_H
