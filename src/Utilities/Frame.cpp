//
// Created by duong on 8/19/24.
//

#include "Frame.h"
#include <SDL_timer.h>


uint16_t Frame::mFrame = {MainWindowSetting::GetFrame()};
std::shared_ptr<Frame> Frame::mInstance = nullptr;

Frame::Frame() {
    mLastTick = SDL_GetTicks();
}

void Frame::Delay() {
    mThisTick = SDL_GetTicks() ;
    uint32_t deta_time = mThisTick - mLastTick;
    if(mDelay > deta_time) {
        SDL_Delay(mDelay - deta_time);
    }
    mLastTick = SDL_GetTicks();

}