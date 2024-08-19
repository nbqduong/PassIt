//
// Created by duong on 8/15/24.
//

#include "Engine.h"
#include "CommandDispatcher.h"
#include "Frame.h"
#include "Input.h"
#include "Setting.h"
#include "SettingFactory.h"
#include "SettingObject.h"
#include "TextureFactory.h"
#include "config.hpp"
#include <SDL_ttf.h>

Engine::Engine()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0  && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
    {
        throw Exception{"SDL could not initialize! SDL_Error: %s\n"+ std::string(SDL_GetError())};
    }
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        throw Exception{"SDL could not initialize! SDL_Error: %s\n"+ std::string(SDL_GetError())};
    }
}

void Engine::Start() {

//    CreateSettingWindow();
//
//    auto objects{ObjectFactory::GetInstance()->GetObject()};
//    auto m = SDL_GetKeyboardState(nullptr);
    auto input = KeyBoard::GetInstance();
//    auto move = MovementManager::GetInstance();
    auto frame = Frame::GetInstance();

    CommandDispatcher command;



//    mWindow->Render();
//    SDL_Delay(3000);
//    mWindow= std::make_unique<Windows>(project_name, MainWindowSetting::GetScreenPX(), MainWindowSetting::GetScreenPY());
    /*-------------------------THE GAME LOOP---------------------------------*/
    while (true)
    {

        auto event = input.GetEvent();
        if(event == UserEvent::emQuit) {
            return;
        }
        command.Dispatch(event);
        frame->Delay();
    }


}

Engine::~Engine() {

    SDL_Log("~Engine Destructor");
    //Quit IMG
    IMG_Quit();
    //Quit SDL subsystems
    SDL_Quit();

    TTF_Quit();
}

void Engine::CreateSettingWindow()
{
    mWindow= std::make_unique<Windows>(std::string(project_name)+" Setting", 800,600, 600,200);

}
