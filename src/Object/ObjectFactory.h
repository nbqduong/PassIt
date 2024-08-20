//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_OBJECTFACTORY_H
#define TEMPLATE_OBJECTFACTORY_H


#include <iostream>
#include <Map.h>
#include "Object.h"
#include "Deco.h"
class ObjectFactory {
    Map& mMapPtr{Map::GetInstance()};
    std::vector<std::shared_ptr<Object>> mObjects;
//    std::shared_ptr<Hero> mHero{std::make_shared<BasicHero>()};

    uint16_t CalculateIndex(const uint8_t& row, const uint8_t& collum);
public:
    ObjectFactory();
    const std::vector<std::shared_ptr<Object>>& GetObject(){return mObjects;}
//    std::shared_ptr<Hero> GetHero(){return mHero;}
//    uint16_t Pos2Index(XYWH Pos){return mMapPtr->GetVectorIndex(GamePosition::GetGamePos(Pos.Y), GamePosition::GetGamePos(Pos.X));}
//    std::shared_ptr<Object> GetObject(XYWH Pos)
//    {return mObjects[Pos2Index(Pos)];}
//    void Erase(XYWH Pos)
//    {mObjects[Pos2Index(Pos)] = std::make_shared<GrassDeco>(GamePosition::GetGamePos(Pos.X),GamePosition::GetGamePos(Pos.Y));}
//    std::shared_ptr<Object> Move(XYWH Pos, Direction dir);
};

#endif //TEMPLATE_OBJECTFACTORY_H
