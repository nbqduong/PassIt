//
// Created by duong on 8/2/24.
//

#ifndef WINDOWS_H
#define WINDOWS_H
#include "SDL2/SDL_image.h"
#include "Text.h"
#include "TextureFactory.h"
#include <Exception.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

class Windows {
protected:
    int mWidth;
    int mHeight;
    std::string mName;
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    Text mText{24};
    TextureFactory mTexture;

public:
    Windows(std::string_view windows_name, uint16_t size_PX, uint16_t size_PY, uint16_t pos_PX=0, uint16_t pos_PY=0);
    virtual void Render();
    inline SDL_Renderer* getRenderer(){return mRenderer;}
    ~Windows();
};

class SettingWindow: public Windows{
public:
    SettingWindow(): Windows(std::string(project_name)+" Setting", 800,600, 600,200){}
    void Render() override;

};



#endif //WINDOWS_H