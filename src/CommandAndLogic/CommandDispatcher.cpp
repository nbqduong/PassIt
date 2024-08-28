//
// Created by duong on 8/19/24.
//

#include "CommandDispatcher.h"


void CommandDispatcher::Dispatch(UserEvent event)
{

    //Popup windows is windows display after game pause this have the highest priority
    if(mPopUpWindow != nullptr)
    {
        //handle pause window: R to resume game, T to restart, SPACE to back to setting window
        switch (event)
        {
        case UserEvent::emR:
            mPopUpWindow = nullptr;
            break;
        case UserEvent::emSpace:
            mPopUpWindow = nullptr;
            mCurrentWindow = make_shared<SettingWindow>();
            break;
        case UserEvent::emT:
            mPopUpWindow = nullptr;
            mCurrentWindow = nullptr;
            mCurrentWindow = make_shared<MainWindow>(mSetting);
            break;
        default:
            break;
        }
    }else
    {
        //handle general: SPACE: setting window switch to Game window, Game window display pause popup
        if(event == UserEvent::emSpace)
        {
            //Main windows have project_name name
            if(0 == mCurrentWindow->GetName().compare(string(project_name))){
                mPopUpWindow = make_shared<PauseWindow>();
            }else
            {
                auto info = mCurrentWindow->GetInformation();
                try {
                    mSetting = std::any_cast<vector<OptionInfo>>(info);
                } catch (const std::bad_any_cast& e) {
                    std::cerr << "Bad cast: " << e.what() << std::endl;
                }

                mCurrentWindow = make_shared<MainWindow>(mSetting);
            }
        }
        else
        {
            //forward command to window process
            mCurrentWindow->ExecuteCommand(event);
        }
    }
}

