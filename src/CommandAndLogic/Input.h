//
// Created by duong on 8/15/24.
//

#ifndef TEMPLATE_INPUT_H
#define TEMPLATE_INPUT_H
#include <SDL.h>
#include <SDL_scancode.h>

#include <memory>

#include <iostream>
#include "Setting.h"
class KeyBoard {
    const Uint8* mKeyState;
    KeyBoard():mKeyState{SDL_GetKeyboardState(nullptr)}{}
    bool mIsPressed{false},
        mEventGetted{false};
    UserEvent mEvent{UserEvent::emNone};

    void Listen();
    void Quit();
    void KeyUp();
    void KeyDown();
    bool GetKey(SDL_Scancode key);
public:
    static KeyBoard& GetInstance(){ static KeyBoard mInstance; return mInstance; }
    UserEvent GetEvent();

};

#endif //TEMPLATE_INPUT_H
