//
// Created by duong on 8/19/24.
//

#include "WindowManager.h"


WindowManager::WindowManager(std::string_view windows_name, uint16_t size_PX, uint16_t size_PY, uint16_t pos_PX, uint16_t pos_PY)

{
    mWindow = make_shared<Windows>(windows_name, size_PX, size_PY, pos_PX, pos_PY);
}
SettingWindow::SettingWindow():WindowManager(std::string(project_name)+" Setting", 800,600, 600,200)
{
    mWindow->SetText(mSetting.GetCurrentSettingText());
    mWindow->Render();
}

any SettingWindow::GetInformation()
{
    return mSetting.GetCurrentOption();

}

void SettingWindow::ExecuteCommand(UserEvent event)
{
    mSetting.HandleCommand(event);
    mWindow->SetText(mSetting.GetCurrentSettingText());
    mWindow->Render();
}

PauseWindow::PauseWindow(): WindowManager(std::string(project_name)+" Pause", 800,600, 600,200)
{
    mWindow->SetText(mObject.GetPauseText());
    mWindow->Render();
}

MainWindow::MainWindow(vector<OptionInfo> info)
{
    //Set main window size
    auto main_size = Convert::WindowSize(info.at(2).Get());
    MainWindowSetting::Instance().Set(main_size.X, main_size.Y);
    //Create window
    mWindow = make_shared<Windows>(std::string(project_name), MainWindowSetting::GetScreenPX(), MainWindowSetting::GetScreenPY());

    //Get MAP and Hero
    shared_ptr<ObjectFactory> object_template = GetObjectTemplate(info.at(1).Get());
    shared_ptr<Hero> hero = GetHero(info.at(0).Get());

    //Lister from hero
    hero->Attach(this);

    //Create game objects
    mObjects = make_shared<ObjectManager>(object_template, hero);
    mMove = make_unique<MovementManager>(mObjects);
    mWindow->SetObject(&mObjects->GetObject());
    mWindow->RegisterObject();
    mWindow->Render();
}

void MainWindow::ExecuteCommand(UserEvent event)
{
    if(event != UserEvent::emNone)
    {
        try {
            mMove->Move(event);
        }
        catch(...)
        {
            return;
        }

//        mWindow->SetObject(mObjects->GetObject());
        mWindow->Render();
    }

}

void MainWindow::Update(any event) {
    mWindow->Render();
}


shared_ptr<ObjectFactory> MainWindow::GetObjectTemplate(const string map) {
    if(map.compare("Ice")==0) {
        return make_shared<IceObjectFactory>();
    }
    else {
        return make_shared<BeachObjectFactory>();
    }
}

shared_ptr<Hero> MainWindow::GetHero(const string hero) {
    if(hero.compare("Simple")==0) {
        return make_shared<SimpleHero>();
    }

    return make_shared<BasicHero>();

}
