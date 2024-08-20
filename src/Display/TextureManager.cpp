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
    for (auto& obj : mObjects) {
        if(obj != nullptr)
            mFactory.Load(obj->GetInfo()->mDrawID, obj->GetInfo()->mFileName);
    }

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

    for (auto& obj : mObjects) {
        if(obj != nullptr)
            mFactory.DrawFrame(obj->GetInfo()->mDrawID, Convert::toPx(obj->GetInfo()->mView), Convert::toPx(obj->GetInfo()->mSource));
    }
}

void TextureManager::SetText(std::vector<std::shared_ptr<TextObject>> texts)
{
    mTexts = texts;
}
void TextureManager::SetObject(const std::vector<std::shared_ptr<Object>> &object)
{
    mObjects = object;
}