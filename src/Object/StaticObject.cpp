//
// Created by duong on 8/20/24.
//

#include "StaticObject.h"


StaticObject::StaticObject(const string link, const std::string &m_id, uint16_t x, uint16_t y, uint32_t width, uint32_t height) :Object(link,m_id,{x,y})
{
//    mInfo.mSource = {0,0, CURRENT::mSourceUnit, CURRENT::mSourceUnit};
    mObjectCount++;
}



void StaticObject::Resize(uint32_t width, uint32_t height) {
    this->mInfo.mView.X = width;
    this->mInfo.mView.Y = height;
}



void StaticObject::ChangeFrame() {
    // if(mFrame >= DEFAULT::mHeroMaxFrame) {
    //     mFrame = 0;
    // }
    // mSrc = Position::GetSrc(mFrame++,0);
}

StaticObject::~StaticObject() {

}

TouchEvent Box::Touched() {
    return TouchEvent::emBlock;
}

TouchEvent Chest::Touched() {
    this->mInfo.mSource.X = 1;
    return TouchEvent::emPass;
}

TouchEvent Water::Touched() {
    return TouchEvent::emPass;
}


TouchEvent Bush::Touched() {
    return TouchEvent::emPass;
}


TouchEvent Grass::Touched() {
    return TouchEvent::emPass;
}

uint16_t StaticObject::mObjectCount = 0;

TouchEvent Gate::Touched() {
    return TouchEvent::emBlock;
}
