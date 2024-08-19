//
// Created by duong on 8/16/24.
//

#ifndef TEMPLATE_TEXTUREMANAGER_H
#define TEMPLATE_TEXTUREMANAGER_H


#include "TextObject.h"
#include "TextureFactory.h"
#include <memory>
#include <vector>
class TextureManager
{

    SDL_Renderer* mRenderer;
    TextureFactory mFactory;
    std::vector<std::shared_ptr<TextObject>> mTexts;
public:
    TextureManager(SDL_Renderer* mRenderer);
    TextureManager()=delete;
    void ShowText();
    void SetText(std::vector<std::shared_ptr<TextObject>> texts);
    ~TextureManager()=default;
};


#endif //TEMPLATE_TEXTUREMANAGER_H
