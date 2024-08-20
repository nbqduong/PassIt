//
// Created by duong on 8/20/24.
//

#include "ObjectFactory.h"
ObjectFactory::ObjectFactory() {
    mObjects.resize(mMapPtr.GetSize()+1,nullptr);

    for (int row = 0; row < mMapPtr.GetHeight(); ++row) {
        for (int column = 0; column < mMapPtr.GetWidth(); ++column) {
            uint16_t index = CalculateIndex(row, column);
            switch (mMapPtr.GetObject(row, column)) {
            case 1:
                mObjects[index]=(std::make_shared<BoxDeco>(column, row));
                break;
            case 2:
                mObjects[index]=(std::make_shared<Bush>(column, row));
                break;
            case 3:
//                mObjects[index]=(std::make_shared<Rock>(column, row));
                break;
            case 4:
                mObjects[index]=(std::make_shared<Chest>(column, row));
                break;
            case 7:
                mObjects[index]=(std::make_shared<Water>(column, row));
                break;
            default:
                mObjects[index]=(std::make_shared<GrassDeco>(column, row));
                break;

            }

        }
    }
//    mObjects.push_back(mHero);
    //    for(int  i = 48 ; i < mObjects.size(); i+=50)
    //    {
    //        std::cout << "index " << i << " "<< mObjects[i]->GetInfo()->mDrawID << std::endl;
    //    }
    std::cout ;
}
//Move dinamic object from pos following dir and return moved object
//std::shared_ptr<Object> ObjectFactory::Move(XYWH Pos, Direction dir) {
//    auto _object = GetObject(Pos);
//    auto moved_object = std::dynamic_pointer_cast<DynamicObject>(_object);
//    if(moved_object != nullptr)
//    {
//        auto next_pos = Collision::Check(dir, Pos);
//        mObjects[Pos2Index(next_pos)] = _object;
//        moved_object->Move(dir);
//        Erase(Pos);
//    }
//    return moved_object;
//}

uint16_t ObjectFactory::CalculateIndex(const uint8_t &row, const uint8_t &collum)
{
    return row*MAX_X+collum;
}

