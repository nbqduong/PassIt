//
// Created by duong on 8/15/24.
//

#include "Input.h"

void KeyBoard::Listen() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        Quit();
        break;
    case SDL_KEYUP:
        KeyUp();
        break;
    case SDL_KEYDOWN:
        KeyDown();
        break;
    default:
        break;
    }
}

void KeyBoard::Quit() {
    mEvent =  UserEvent::emQuit;
}

void KeyBoard::KeyUp() {
    mIsPressed = false;
}

void KeyBoard::KeyDown() {
    if(mIsPressed == false) {

        if(GetKey(SDL_SCANCODE_DOWN) == 1) mEvent =  UserEvent::emDown;
        if(GetKey(SDL_SCANCODE_UP) == 1) mEvent =  UserEvent::emUp;
        if(GetKey(SDL_SCANCODE_LEFT) == 1) mEvent =  UserEvent::emLeft;
        if(GetKey(SDL_SCANCODE_RIGHT) == 1) mEvent =  UserEvent::emRight;
        if(GetKey(SDL_SCANCODE_SPACE) == 1) mEvent =  UserEvent::emSpace;
        if(GetKey(SDL_SCANCODE_R) == 1) mEvent =  UserEvent::emR;
        if(GetKey(SDL_SCANCODE_T) == 1) mEvent =  UserEvent::emT;
        if(GetKey(SDL_SCANCODE_ESCAPE) == 1) mEvent =  UserEvent::emQuit;
    }
    mIsPressed = true;
}

bool KeyBoard::GetKey(SDL_Scancode key) {
    return (mKeyState[key] == 1) ? true : false;

}

UserEvent KeyBoard::GetEvent() {
    Listen();
    if(mIsPressed == false) {
        UserEvent tmp = mEvent;
        mEvent = UserEvent::emNone;
        return tmp;
    }
    return UserEvent::emNone;
}
