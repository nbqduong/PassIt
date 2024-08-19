//
// Created by duong on 8/19/24.
//

#ifndef TEMPLATE_ABSTRACTMANAGER_H
#define TEMPLATE_ABSTRACTMANAGER_H


#include "Input.h"
class AbstractManager
{

public:
    void ExecuteEvent(UserEvent event);
};

class AbstractSetting: public AbstractManager
{

public:
    void ExecuteEvent(UserEvent event);
};

class AbstractMain: public AbstractManager
{

public:
    void ExecuteEvent(UserEvent event);
};

class AbstractPause: public AbstractManager
{

public:
    void ExecuteEvent(UserEvent event);
};

#endif //TEMPLATE_ABSTRACTMANAGER_H
