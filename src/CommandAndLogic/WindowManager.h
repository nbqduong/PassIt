//
// Created by duong on 8/19/24.
//

#ifndef TEMPLATE_WINDOWMANAGER_H
#define TEMPLATE_WINDOWMANAGER_H


#include "Input.h"
#include "MovementManager.h"
#include "ObjectManager.h"
#include "SettingObject.h"
#include "Window.h"
#include "config.hpp"
#include <any>

#include "ObserverPattern.h"
#include "PauseObject.h"
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


class MainWindow : public WindowManager, public Observer
{
public:
    MainWindow(vector<OptionInfo> info);
    void ExecuteCommand(UserEvent event);
    void Update(any event) override;
private:
    shared_ptr<ObjectManager> mObjects;
    unique_ptr<MovementManager> mMove;
    shared_ptr<ObjectFactory> GetObjectTemplate(const string map);
    shared_ptr<Hero> GetHero(const string hero);

};

class PauseWindow : public WindowManager
{
public:
    PauseWindow();
    void ExecuteCommand(UserEvent event){};

private:
    PauseObject &mObject{PauseObject::GetInstance()};
};

#endif //TEMPLATE_WINDOWMANAGER_H
