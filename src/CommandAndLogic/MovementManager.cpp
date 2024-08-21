//
// Created by duong on 8/20/24.
//

#include "MovementManager.h"

MovementManager::MovementManager(std::shared_ptr<ObjectFactory> objects)
{
    mObjects = objects;
    mHero = mObjects->GetHero();
}


void MovementManager::Move(UserEvent event) {
    switch (event) {
    case UserEvent::emUp:
        HandleCollision(UserEvent::emUp);
        break;
    case UserEvent::emDown:
        HandleCollision(UserEvent::emDown);

        break;
    case UserEvent::emLeft:
        HandleCollision(UserEvent::emLeft);

        break;
    case UserEvent::emRight:
        HandleCollision(UserEvent::emRight);

        break;
    default:
        break;
    }
}

void MovementManager::HandleCollision(UserEvent direction) {
    Co col = Position::Check(direction,mHero->GetInfo().mView);
    auto object = mObjects->GetObject(col);
    if(object->Touched() != TouchEvent::emBlock) {
        //rock above hero may fall
        auto rock_pos =  Position::Check(UserEvent::emUp,mHero->GetInfo().mView);
        mHero->Move(direction);
        RockFall(rock_pos);
//
//        std::cout <<"Hero walk on " <<mObjects->GetObject(mHero->GetInfo().mView)->GetInfo().mDrawID << std::endl;
        if(object->GetInfo().mDrawID == "Bush")
        {
            GrassInterract(object->GetInfo().mView);
        }
    }
    else if(object->GetInfo().mDrawID == "Rock")
    {
        if(PushRock(direction, object->GetInfo().mView) != TouchEvent::emBlock)
        {
            RockFall( Position::Check(UserEvent::emUp,mHero->GetInfo().mView));
            mHero->Move(direction);
        }
    }
}

void MovementManager::GrassInterract(Co Pos) {
    mObjects->Erase({Pos});

}

void MovementManager::RockFall(Co pos) {
    auto rock_obj = mObjects->GetObject(pos);
    if(rock_obj->GetInfo().mDrawID == "Rock")
    {

        //now up_object is rock
        //check whether rock's down is grass or not, continuous falling if down is grass
        auto down_rock_pos = Position::Check(UserEvent::emDown,rock_obj->GetInfo().mView);
        auto down_rock_object =  mObjects->GetObject(down_rock_pos);
        while(down_rock_object->GetInfo().mDrawID == "Grass")
        {
//            //recursive check whether other rock on
            auto up_rock_pos = Position::Check(UserEvent::emUp,rock_obj->GetInfo().mView);
            mObjects->Move(rock_obj->GetInfo().mView,UserEvent::emDown);
            RockFall(up_rock_pos);

            //now the rock falled to down position
            auto rock_pos = down_rock_pos;
            rock_obj = mObjects->GetObject(down_rock_pos);

            //update down position for rock
            down_rock_pos = Position::Check(UserEvent::emDown,rock_obj->GetInfo().mView);
            down_rock_object =  mObjects->GetObject(down_rock_pos);

            //rock fall to hero head
            if(down_rock_pos == mHero->GetInfo().mView)
            {
                //handle hero action

                return;
            }
        }

    }
}

TouchEvent MovementManager::PushRock(UserEvent dir, Co pos) {
    //not push up down
    if(dir == UserEvent::emDown || dir == UserEvent::emUp) return TouchEvent::emBlock;

    //not push to obstacle
    auto nextto_rock_pos = Position::Check(dir,pos);
    if(mObjects->GetObject(nextto_rock_pos)->GetInfo().mDrawID != "Grass") return TouchEvent::emBlock;

    //push to grass
    mObjects->Move(pos, dir);

    //while pushing, rock may fall
    RockFall(Position::Check(dir, pos));
    return TouchEvent::emPass;
}