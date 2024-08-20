//
// Created by duong on 8/19/24.
//

#include "WindowManager.h"

WindowManager::WindowManager(std::string_view windows_name, uint16_t size_PX, uint16_t size_PY, uint16_t pos_PX, uint16_t pos_PY)
    :Windows(windows_name, size_PX, size_PY, pos_PX, pos_PY)
{

}
SettingWindow::SettingWindow():WindowManager(std::string(project_name)+" Setting", 800,600, 600,200)
{
    SetText(mSetting.GetCurrentSettingText());
    Render();
}

any SettingWindow::GetInformation()
{
    return mSetting.GetCurrentOption();

}

void SettingWindow::ExecuteCommand(UserEvent event)
{
    mSetting.HandleCommand(event);
    SetText(mSetting.GetCurrentSettingText());
    Render();
}

MainWindow::MainWindow(): WindowManager(std::string(project_name), MainWindowSetting::GetScreenPX(), MainWindowSetting::GetScreenPY())
{
    Render();
}

PauseWindow::PauseWindow(): WindowManager(std::string(project_name)+" Pause", 800,600, 600,200)
{
    Render();
}