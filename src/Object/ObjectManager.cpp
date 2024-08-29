//
// Created by duong on 8/20/24.
//

#include "ObjectManager.h"
#include "DynamicObject.h"
#include "Position.h"
ObjectManager::ObjectManager(shared_ptr<ObjectFactory> factory, shared_ptr<Hero> hero):mFactory{factory}, mHero{hero} {
    mObjects.resize(mMapPtr.GetSize()+1,nullptr);

    for (int row = 0; row < mMapPtr.GetHeight(); ++row) {
        for (int column = 0; column < mMapPtr.GetWidth(); ++column) {
            uint16_t index = CalculateIndex(row, column);
            switch (mMapPtr.GetObject(row, column)) {
            case 1:
                mObjects[index]=(mFactory->GetBox(column, row));
                break;
            case 2:
                mObjects[index]=(mFactory->GetBush(column, row));

                break;
            case 3:
                mObjects[index]=(mFactory->GetRock(column, row));

                break;
            case 4:
                mObjects[index]=(mFactory->GetChest(column, row));

                break;
            case 6:
                mObjects[index]=(mFactory->GetGate(column, row));

            break;
            // case 7:
                // mObjects[index]=(std::make_shared<Water>(column, row));
                // mObjects[index]=(mFactory->Get(column, row));

                // break;
            default:
                mObjects[index]=(mFactory->GetGrass(column, row));

                break;

            }

        }
    }
    mObjects.push_back(mHero);
}

//Move dinamic object from pos following dir and return moved object
std::shared_ptr<Object> ObjectManager::Move(Co Pos, UserEvent dir){
    auto _object = GetObject(Pos);
    auto moved_object = std::dynamic_pointer_cast<DynamicObject>(_object);
    if(moved_object != nullptr)
    {
        auto next_pos = Position::Check(dir, Pos);
        mObjects[Pos2Index(next_pos)] = _object;
        moved_object->Move(dir);
        Erase(Pos);
    }
    return moved_object;
}

uint16_t ObjectManager::CalculateIndex(const uint8_t &row, const uint8_t &collum)
{
    return row*MAX_X+collum;
}

