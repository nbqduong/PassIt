//
// Created by duong on 8/20/24.
//


#include "Hero.h"
#include "Position.h"


Hero::Hero(const string link, const std::string &m_id, uint16_t x, uint16_t y, uint32_t width, uint32_t height)
    :Object(link,m_id,{x,y})
{
    mInfo.mSource= {0,0};
}



void Hero::Move(uint32_t x, uint32_t y) {
    this->mInfo.mView.X=x;
    this->mInfo.mView.Y=y;
}

void Hero::Move(UserEvent dir) {
    Position::Move(dir, this->mInfo.mView);
}

//void Hero::Resize(uint32_t width, uint32_t height) {
//    this->mInfo.mView.X = width;
//    this->mInfo.mView.height = height;
//}

//void Hero::ChangeFrame() {
//    if(mFrame >= CURRENT::mHeroMaxFrame) {
//        mFrame = 0;
//    }
//    mInfo.mSource = GamePosition::GetSrc(mFrame++,0);
//}

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