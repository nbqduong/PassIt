//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_HERO_H
#define TEMPLATE_HERO_H

#include "Object.h"
using std::string;
class Hero:public Object {
    uint16_t mFrame{0};
public:
    Hero(const string link, const std::string &m_id , uint16_t x, uint16_t y, uint32_t width = 1, uint32_t height = 1);

    virtual void Move(uint32_t x, uint32_t y);
    virtual void Move(UserEvent dir);
//    virtual void Resize(uint32_t width, uint32_t height);

//    virtual void ChangeFrame();
    TouchEvent Touched()override{return TouchEvent::emPass;};
    ~Hero();
};
class BasicHero : public Hero {
public:
    BasicHero(uint8_t collum = 0, uint8_t row = MAX_Y- 3, uint8_t width = 1, uint8_t height = 1);
};

class SimpleHero : public Hero {
public:
    SimpleHero(uint8_t collum = 0, uint8_t row = MAX_Y- 3, uint8_t width = 1, uint8_t height = 1);
};

#endif //TEMPLATE_HERO_H
