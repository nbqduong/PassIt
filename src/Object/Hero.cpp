//
// Created by duong on 8/20/24.
//


#include "Hero.h"
#include "Position.h"
#include <SDL_timer.h>


Hero::Hero(const string link, const std::string &m_id, uint16_t x, uint16_t y, uint32_t width, uint32_t height)
    :Object(link,m_id,{x,y})
{
    mInfo.mSource= {0,0};
}



void Hero::Move(uint32_t x, uint32_t y) {
    ChangeFrame();
    this->mInfo.mView.X=x;
    this->mInfo.mView.Y=y;
}

void Hero::Move(UserEvent dir) {
    ChangeFrame();
    Position::Move(dir, this->mInfo.mView);
}

void Hero::ChangeFrame() {
    for (int x = 0; x < 2 ; x++) {
        this->mInfo.mSource.X = this->mInfo.mSource.X >= 1 ?
            0 : this->mInfo.mSource.X+1;
        SDL_Delay(50);
        Notify();
    }
}

Hero::~Hero() {
//    Debug::BasePrint(mInfo.mID.c_str()," Hero destructor");
}




BasicHero::BasicHero(uint8_t collum, uint8_t row, uint8_t width, uint8_t height)
    :Hero(Convert::Asset("BasicHero"), "BasicHero", collum,row,width,height)
{
    static uint16_t count = 0;
    mInfo.mID = mInfo.mDrawID + std::to_string(count++);
}

SimpleHero::SimpleHero(uint8_t collum, uint8_t row, uint8_t width, uint8_t height)
    :Hero(Convert::Asset("SimpleHero"), "SimpleHero",collum,row,width,height)
{
    static uint16_t count = 0;
    mInfo.mID = mInfo.mDrawID + std::to_string(count++);
}