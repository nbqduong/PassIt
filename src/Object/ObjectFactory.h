//
// Created by duong on 24/08/2024.
//

#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include <memory>

#include "DynamicObject.h"
#include "StaticObject.h"

using std::shared_ptr;
using std::make_shared;

class ObjectFactory {
public:
    virtual ~ObjectFactory() {};
    virtual shared_ptr<Grass> GetGrass(uint16_t x, uint16_t y) = 0;
    virtual shared_ptr<Box> GetBox(uint16_t x, uint16_t y) = 0;
    virtual shared_ptr<Bush> GetBush(uint16_t x, uint16_t y) = 0;
    virtual shared_ptr<Rock> GetRock(uint16_t x, uint16_t y) = 0;
    virtual shared_ptr<Chest> GetChest(uint16_t x, uint16_t y) = 0;
    virtual shared_ptr<Gate> GetGate(uint16_t x, uint16_t y) = 0;

};

class BeachObjectFactory : public ObjectFactory {
  public:
    shared_ptr<Grass> GetGrass(uint16_t x, uint16_t y) override {
        return make_shared<BeachGrass>(x,y);
    }
    shared_ptr<Box> GetBox(uint16_t x, uint16_t y) override {
        return make_shared<BeachBox>(x,y);
    }
    shared_ptr<Bush> GetBush(uint16_t x, uint16_t y) override {
        return make_shared<BeachBush>(x,y);
    }
    shared_ptr<Chest> GetChest(uint16_t x, uint16_t y) override {
        return make_shared<BeachChest>(x,y);
    }
    shared_ptr<Rock> GetRock(uint16_t x, uint16_t y) override {
        return make_shared<BeachRock>(x,y);
    }
    shared_ptr<Gate> GetGate(uint16_t x, uint16_t y) override {
        return make_shared<BeachGate>(x,y);
    }
};

class IceObjectFactory : public ObjectFactory {
public:
    shared_ptr<Grass> GetGrass(uint16_t x, uint16_t y) override {
        return make_shared<IceGrass>(x,y);
    }
    shared_ptr<Box> GetBox(uint16_t x, uint16_t y) override {
        return make_shared<IceBox>(x,y);
    }
    shared_ptr<Bush> GetBush(uint16_t x, uint16_t y) override {
        return make_shared<IceBush>(x,y);
    }
    shared_ptr<Chest> GetChest(uint16_t x, uint16_t y) override {
        return make_shared<IceChest>(x,y);
    }
    shared_ptr<Rock> GetRock(uint16_t x, uint16_t y) override {
        return make_shared<IceRock>(x,y);
    }
    shared_ptr<Gate> GetGate(uint16_t x, uint16_t y) override {
        return make_shared<IceGate>(x,y);
    }
};

#endif //OBJECTFACTORY_H
