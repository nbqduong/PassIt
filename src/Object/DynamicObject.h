//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_DYNAMICOBJECT_H
#define TEMPLATE_DYNAMICOBJECT_H


#include "Object.h"

class DynamicObject : public Object {

    uint16_t mFrame{0};
public:
    DynamicObject(const string link, const std::string &m_id, uint16_t x, uint16_t y, uint32_t width, uint32_t height);
    //    virtual void Resize(uint32_t width, uint32_t height);
    //    virtual void ChangeFrame();
    virtual void Move(UserEvent dir)=0;
    virtual TouchEvent Touched() override=0;
    ~DynamicObject(){};

};

class Rock : public DynamicObject {
public:
    Rock(uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
        :DynamicObject(Convert::Asset("Rock"), "Rock", collum,row,width,height) {}
    TouchEvent Touched() override;
    void Move(UserEvent dir) override;

};


#endif //TEMPLATE_DYNAMICOBJECT_H
