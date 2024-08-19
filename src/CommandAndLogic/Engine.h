//
// Created by duong on 8/15/24.
//

#ifndef TEMPLATE_ENGINE_H
#define TEMPLATE_ENGINE_H


#include "Window.h"


class Engine
{
    std::unique_ptr<Windows> mWindow{nullptr};
    Engine();
    void CreateSettingWindow();

public:
    void Start();
    ~Engine();

    static Engine &GetInstance(){
        static Engine mEngine;
        return mEngine;
    };
};


#endif //TEMPLATE_ENGINE_H
