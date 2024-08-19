//
// Created by duong on 8/16/24.
//

#include "TextureManager.h"


TextureManager::TextureManager(SDL_Renderer* mRenderer) : mRenderer{mRenderer}
{
    mFactory.setRenderer(mRenderer);

}
void TextureManager::ShowText()
{
    for (auto& obj : mTexts) {
        if(obj != nullptr)
        {
            auto info = obj->GetInfo();
            mFactory.setFont(info.size);
            mFactory.addText(info.ID, info.content, info.color);

        }

    }
    for (auto& obj : mTexts) {
        if(obj != nullptr)
        {
            auto info = obj->GetInfo();
            mFactory.viewText(info.ID, info.pos.X, info.pos.Y);

        }

    }
}

void TextureManager::SetText(std::vector<std::shared_ptr<TextObject>> texts)
{
    mTexts = texts;
}
