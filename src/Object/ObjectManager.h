//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_OBJECTFACTORY_H
#define TEMPLATE_OBJECTFACTORY_H


#include "StaticObject.h"
#include "Hero.h"
#include "Object.h"
#include <Map.h>
#include <iostream>

#include "ObjectFactory.h"

class ObjectManager {
    shared_ptr<ObjectFactory> mFactory;
    Map& mMapPtr{Map::GetInstance()};
    std::vector<std::shared_ptr<Object>> mObjects;
    std::shared_ptr<Hero> mHero;

    uint16_t CalculateIndex(const uint8_t& row, const uint8_t& collum);
public:
    ObjectManager(shared_ptr<ObjectFactory> factory, shared_ptr<Hero> hero);
    const std::vector<std::shared_ptr<Object>>& GetObject(){return mObjects;}


    //inline functions
    std::shared_ptr<Hero> GetHero()
        {return mHero;}
    uint16_t Pos2Index(const Co &Pos)
        {return mMapPtr.GetVectorIndex(Pos.Y, Pos.X);}
    std::shared_ptr<Object> GetObject(const Co &Pos)
        {return mObjects[Pos2Index(Pos)];}
    void Erase(const Co &Pos)
        {mObjects[Pos2Index(Pos)] = mFactory->GetGrass(Pos.X, Pos.Y);}
    std::shared_ptr<Object> Move(Co Pos, UserEvent dir);
};

#endif //TEMPLATE_OBJECTFACTORY_H
