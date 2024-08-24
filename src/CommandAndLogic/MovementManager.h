//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_MOVEMENTMANAGER_H
#define TEMPLATE_MOVEMENTMANAGER_H

#include <Hero.h>
#include <memory>
#include "Position.h"
#include "ObjectManager.h"


class MovementManager {
    static std::shared_ptr<MovementManager> mInstance;
    std::shared_ptr<ObjectManager> mObjects;
    std::shared_ptr<Hero> mHero;

public:
    MovementManager(std::shared_ptr<ObjectManager> objects);
    void Move(UserEvent event );
    void HandleCollision(UserEvent direction);
    void GrassInterract(Co pos);
    void RockFall(Co pos);
    TouchEvent PushRock(UserEvent dir, Co pos);

};


#endif //TEMPLATE_MOVEMENTMANAGER_H
