//
// Created by duong on 8/20/24.
//

#include "Position.h"
//uint16_t GamePosition::mScale{CURRENT::mScale};
uint16_t Position::mViewFactor{uint16_t(MainWindowSetting::GetViewUnit())};
uint16_t Position::mSrcFactor{uint16_t(MainWindowSetting::GetSourceUnit())};

bool Position::Move(UserEvent dir, Co &cor){
    switch (dir) {
    case UserEvent::emUp:
        if(cor.Y >= 1) {
            cor.Y -= 1;
            return true;
        }
        break;
    case UserEvent::emDown:
        if(cor.Y < (MAX_Y) - 1) {
            cor.Y += 1;
            return true;
        }
        break;
    case UserEvent::emLeft:
        if(cor.X >= 1) {
            cor.X -= 1;
            return true;
        }
        break;
    case UserEvent::emRight:
        if(cor.X < (MAX_X)- 1) {
            cor.X += 1;
            return true;
        }
    default:
        break;
    }
    return false;
}

Co Position::Check(UserEvent dir, Co cor)
{
    Move(dir, cor);
    return cor;
}