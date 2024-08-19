//
// Created by duong on 8/19/24.
//

#ifndef TEMPLATE_FRAME_H
#define TEMPLATE_FRAME_H


#include <cstdint>
#include <memory>
#include <Setting.h>


class Frame {
    const uint16_t mSecond = 1000;
    static uint16_t mFrame;
    uint16_t mDelay{static_cast<uint16_t>(mSecond/mFrame)};
    uint32_t mLastTick;
    uint32_t mThisTick;
    static std::shared_ptr<Frame> mInstance;
    Frame();
public:
    static std::shared_ptr<Frame> GetInstance(){ return mInstance = (mInstance != nullptr)? mInstance : std::shared_ptr<Frame>(new Frame());}
    void Delay();

};

#endif //TEMPLATE_FRAME_H
