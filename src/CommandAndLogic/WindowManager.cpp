//
// Created by duong on 8/19/24.
//

#include "WindowManager.h"
#include "ObjectFactory.h"

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
    mWindow->Render();
}

MainWindow::MainWindow(vector<OptionInfo> info)
{
    //Set main window size
    auto main_size = Convert::WindowSize(info.at(2).Get());
    MainWindowSetting::Instance().Set(main_size.X, main_size.Y);
    //Create window
    mWindow = make_shared<Windows>(std::string(project_name), MainWindowSetting::GetScreenPX(), MainWindowSetting::GetScreenPY());

    //Create game objects
    ObjectFactory f;
    auto a = f.GetObject();
    mWindow->SetObject(a);

    mWindow->Render();
}