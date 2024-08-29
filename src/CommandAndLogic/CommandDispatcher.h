//
// Created by duong on 8/19/24.
//

#ifndef TEMPLATE_COMMANDDISPATCHER_H
#define TEMPLATE_COMMANDDISPATCHER_H


#include "AbstractManager.h"
#include "Input.h"
#include "WindowManager.h"
#include <SDL_events.h>

using std::make_shared;
using std::make_shared;

class CommandDispatcher : private Observer, public Subject
{
public:
    //Dispatch even
    void Dispatch(UserEvent event);
    void Update(any event) override;
private:
    std::shared_ptr<WindowManager> mCurrentWindow{make_shared<SettingWindow>()},
    mPopUpWindow{nullptr};
    vector<OptionInfo> mSetting;

    void CreateMainWindow();

};


#endif //TEMPLATE_COMMANDDISPATCHER_H
