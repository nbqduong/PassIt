//
// Created by duong on 8/20/24.
//

#include "Deco.h"


Deco::Deco(const string link, const std::string &m_id, uint16_t x, uint16_t y, uint32_t width, uint32_t height) :Object(link,m_id,{x,y})
{
//    mInfo.mSource = {0,0, CURRENT::mSourceUnit, CURRENT::mSourceUnit};
    mObjectCount++;
}



void Deco::Resize(uint32_t width, uint32_t height) {
    this->mInfo.mView.X = width;
    this->mInfo.mView.Y = height;
}



void Deco::ChangeFrame() {
    // if(mFrame >= DEFAULT::mHeroMaxFrame) {
    //     mFrame = 0;
    // }
    // mSrc = Position::GetSrc(mFrame++,0);
}

Deco::~Deco() {

}

BoxDeco::BoxDeco(uint8_t collum, uint8_t row, uint8_t width, uint8_t height)
    :Deco((std::string(_materials)+"Box.png"), "Box", collum,row,width,height) {
    mID = "Box" + std::to_string(mObjectCount);
}

TouchEvent BoxDeco::Touched() {
    return TouchEvent::emBlock;
}

TouchEvent Chest::Touched() {
    return TouchEvent::emPass;
}





TouchEvent Water::Touched() {
    return TouchEvent::emPass;
}


TouchEvent Bush::Touched() {
    return TouchEvent::emPass;
}


TouchEvent GrassDeco::Touched() {
    return TouchEvent::emPass;
}
uint16_t Deco::mObjectCount = 0;
