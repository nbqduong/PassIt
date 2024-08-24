//
// Created by duong on 8/20/24.
//

#include "DynamicObject.h"
#include "Position.h"

DynamicObject::DynamicObject(const string link, const std::string &m_id, uint16_t x, uint16_t y, uint32_t width, uint32_t height) :Object(link,m_id, {x,y})
{
}

TouchEvent Rock::Touched() {
    return TouchEvent::emBlock;
}

void Rock::Move(UserEvent dir) {
    Position::Move(dir, this->mInfo.mView);
}