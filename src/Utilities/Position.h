//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_POSITION_H
#define TEMPLATE_POSITION_H

#include "Setting.h"

class Position
{
    static uint16_t mScale;
    static uint16_t mViewFactor;
    static uint16_t mSrcFactor;
//    static std::shared_ptr<GamePosition> mInstance;

public:
//    static std::shared_ptr<GamePosition> GetInstance(){return mInstance = (mInstance != nullptr)? mInstance : std::shared_ptr<Position>(new Position());}
//    static XYWH Get(uint16_t colum, uint16_t row, uint16_t width=1, uint16_t height=1);
//    static XYWH GetSrc(uint16_t colum, uint16_t row, uint16_t width=1, uint16_t height=1);
    static bool Move(UserEvent dir, Co &cor);
    static Co Check(UserEvent dir, Co cor);
//    static uint16_t GetGamePos(uint16_t Pos);
};

#endif //TEMPLATE_POSITION_H
