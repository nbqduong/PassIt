//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_OBJECTFACTORY_H
#define TEMPLATE_OBJECTFACTORY_H


#include "Deco.h"
#include "Hero.h"
#include "Object.h"
#include <Map.h>
#include <iostream>
class ObjectFactory {
    Map& mMapPtr{Map::GetInstance()};
    std::vector<std::shared_ptr<Object>> mObjects;
    std::shared_ptr<Hero> mHero{std::make_shared<BasicHero>()};

    uint16_t CalculateIndex(const uint8_t& row, const uint8_t& collum);
public:
    ObjectFactory();
    const std::vector<std::shared_ptr<Object>>& GetObject(){return mObjects;}


    //inline functions
    std::shared_ptr<Hero> GetHero()
        {return mHero;}
    uint16_t Pos2Index(const Co &Pos)
        {return mMapPtr.GetVectorIndex(Pos.Y, Pos.X);}
    std::shared_ptr<Object> GetObject(const Co &Pos)
        {return mObjects[Pos2Index(Pos)];}
    void Erase(const Co &Pos)
        {mObjects[Pos2Index(Pos)] = std::make_shared<GrassDeco>(Pos.X,Pos.Y);}
    std::shared_ptr<Object> Move(Co Pos, UserEvent dir);
};

#endif //TEMPLATE_OBJECTFACTORY_H
