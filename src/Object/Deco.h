//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_DECO_H
#define TEMPLATE_DECO_H

#include <Object.h>
#include "string"
#include "iostream"

using std::string;

class Deco:public Object{
    uint16_t mFrame{0};
protected:
    static uint16_t mObjectCount;
public:
    Deco(string link, const std::string &m_id, uint16_t x, uint16_t y, uint32_t width, uint32_t height);
    virtual void Resize(uint32_t width, uint32_t height);

    virtual void ChangeFrame();
    virtual TouchEvent Touched() override{return TouchEvent::emPass;};
    ~Deco();
};

class BoxDeco : public Deco {

    std::string mID;
public:
    BoxDeco(uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1);
    TouchEvent Touched() override;


};

class GrassDeco : public Deco {
public:
    GrassDeco(uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
        :Deco(Convert::Asset("Grass"), "Grass", collum,row,width,height) {}
    TouchEvent Touched() override;

};

class Chest : public Deco {
public:
    Chest(uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
        :Deco(Convert::Asset("Chest"), "Chest", collum,row,width,height) {}
    TouchEvent Touched() override;

};

class Water : public Deco {
public:
    Water(uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
        :Deco(Convert::Asset("WaterC"), "Water", collum,row,width,height) {}
    TouchEvent Touched() override;

};

class Bush : public Deco {
public:
    Bush(uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
        :Deco(Convert::Asset("Bush").c_str(), "Bush", collum,row,width,height) {}
    TouchEvent Touched() override;

};
#endif //TEMPLATE_DECO_H
