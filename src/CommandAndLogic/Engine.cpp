//
// Created by duong on 8/15/24.
//

#include "Engine.h"
#include "Setting.h"
#include "Text.h"
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

     mWindow= std::make_unique<SettingWindow>();


}

void Engine::Start() {

//    auto objects{ObjectFactory::GetInstance()->GetObject()};
//    auto m = SDL_GetKeyboardState(nullptr);
//    auto input = KeyBoard::GetInstance();
//    auto move = MovementManager::GetInstance();
//    auto frame = Frame::GetInstance();

    /*-------------------------THE GAME LOOP---------------------------------*/
//    while (true)
    {



//        TextureFactory::GetInstance().Load("tree",std::string(_materials)+"/tree.png");
    mWindow->Render();
//        auto event = input->GetEvent();
//        if(event == UserEvent::emQuit) {
//            return;
//        }
//        move->Move(event);
//        frame->Delay();
        SDL_Delay(5000);
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
