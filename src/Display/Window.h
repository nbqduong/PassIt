//
// Created by duong on 8/2/24.
//

#ifndef WINDOWS_H
#define WINDOWS_H
#include "SDL2/SDL_image.h"

#include "TextureFactory.h"
#include "TextureManager.h"
#include <Exception.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

using std::vector;
using std::shared_ptr;

class Windows {
protected:
    int mWidth;
    int mHeight;
    std::string mName;
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    std::unique_ptr<TextureManager> mTexture{nullptr};

public:
    Windows(std::string_view windows_name, uint16_t size_PX, uint16_t size_PY, uint16_t pos_PX=0, uint16_t pos_PY=0);
    Windows() = delete;
    ~Windows();
    virtual void Render();
    void SetText(vector<shared_ptr<TextObject>> texts);
    string_view GetName(){return mName;}
};

#endif //WINDOWS_H