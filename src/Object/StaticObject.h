//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_DECO_H
#define TEMPLATE_DECO_H

#include <Object.h>
#include "string"
#include "iostream"

using std::string;

class StaticObject:public Object{
    uint16_t mFrame{0};
protected:
    static uint16_t mObjectCount;
public:
    StaticObject(string link, const std::string &m_id, uint16_t x, uint16_t y, uint32_t width, uint32_t height);
    virtual void Resize(uint32_t width, uint32_t height);

    virtual void ChangeFrame();
    virtual TouchEvent Touched() override{return TouchEvent::emPass;};
    ~StaticObject();
};


//---------------------------BOX-----------------------------------
class Box : public StaticObject {

    std::string mID;
public:
    Box(const string link, uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
    :StaticObject(link, "Box", collum,row,width,height) {
        mID = "Box" + std::to_string(mObjectCount);
    }
    TouchEvent Touched() override;
};

class BeachBox : public Box {
    public:
    BeachBox(uint8_t collum, uint8_t row, uint8_t width=1, uint8_t height=1)
        :Box(Convert::Asset("Beach/Box"), collum, row,width,height) {}
};

class IceBox : public Box {
public:
    IceBox(uint8_t collum, uint8_t row, uint8_t width=1, uint8_t height=1)
        :Box(Convert::Asset("Ice/Box"), collum, row,width,height) {}
};

//---------------------------GRASS-----------------------------------
class Grass : public StaticObject {
public:
    Grass(const string link, uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
        :StaticObject(link, "Grass", collum,row,width,height) {}
    TouchEvent Touched() override;

};

class BeachGrass : public Grass {
public:
    BeachGrass(uint8_t collum, uint8_t row, uint8_t width=1, uint8_t height=1)
        :Grass(Convert::Asset("Beach/Grass"), collum, row,width,height) {}
};

class IceGrass : public Grass {
public:
    IceGrass(uint8_t collum, uint8_t row, uint8_t width=1, uint8_t height=1)
        :Grass(Convert::Asset("Ice/Grass"), collum, row,width,height) {}
};

//---------------------------CHEST-----------------------------------

class Chest : public StaticObject {
public:
    Chest(const string link, uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
        :StaticObject(link, "Chest", collum,row,width,height) {}
    TouchEvent Touched() override;

};
class BeachChest : public Chest {
public:
    BeachChest(uint8_t collum, uint8_t row, uint8_t width=1, uint8_t height=1)
        :Chest(Convert::Asset("Beach/Chest"), collum, row,width,height) {}
};

class IceChest : public Chest {
public:
    IceChest(uint8_t collum, uint8_t row, uint8_t width=1, uint8_t height=1)
        :Chest(Convert::Asset("Ice/Chest"), collum, row,width,height) {}
};

//---------------------------WATER-----------------------------------

class Water : public StaticObject {
public:
    Water(const string link, uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
        :StaticObject(link, "Water", collum,row,width,height) {}
    TouchEvent Touched() override;

};
class BeachWater : public Water {
public:
    BeachWater(uint8_t collum, uint8_t row, uint8_t width=1, uint8_t height=1)
        :Water(Convert::Asset("Beach/Water"), collum, row,width,height) {}
};

class IceWater : public Water {
public:
    IceWater(uint8_t collum, uint8_t row, uint8_t width=1, uint8_t height=1)
        :Water(Convert::Asset("Ice/Water"), collum, row,width,height) {}
};


//---------------------------BUSH-----------------------------------

class Bush : public StaticObject {
public:
    Bush(const string link, uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
        :StaticObject(link, "Bush", collum,row,width,height) {}
    TouchEvent Touched() override;

};

class BeachBush : public Bush {
public:
    BeachBush(uint8_t collum, uint8_t row, uint8_t width=1, uint8_t height=1)
        :Bush(Convert::Asset("Beach/Bush"), collum, row,width,height) {}
};
class IceBush : public Bush {
public:
    IceBush(uint8_t collum, uint8_t row, uint8_t width=1, uint8_t height=1)
        :Bush(Convert::Asset("Ice/Bush"), collum, row,width,height) {}
};
#endif //TEMPLATE_DECO_H
