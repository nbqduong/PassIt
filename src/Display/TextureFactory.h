//
// Created by duong on 8/16/24.
//

#ifndef TEMPLATE_TEXTUREFACTORY_H
#define TEMPLATE_TEXTUREFACTORY_H


#include "SDL_image.h"
#include "Setting.h"
#include "config.hpp"
#include <SDL_ttf.h>
#include <map>
#include <string>
class TextureFactory
{

    std::map<std::string, SDL_Texture*> mTextureMap;
    std::map<std::string, Co> mTextSie;
    SDL_Renderer* mRenderer;
    TTF_Font* gFont {NULL};

public:

    TextureFactory(uint16_t  text_size = 12,std::string font_path = std::string(_materials)+"Myfont.ttf");
    ~TextureFactory();

    //for image
    bool Load(std::string id, std::string filename);
    void Drop(std::string id);
    void Clean();

//    void Draw(std::string id, int x, int y, int width, int heigt, SDL_RendererFlip flip=SDL_FLIP_NONE);
    void DrawFrame  ( std::string id, Co src_pos, Co src_range, Co dst_pos, Co dst_range, SDL_RendererFlip flip=SDL_FLIP_NONE) const;
    void setRenderer(SDL_Renderer* renderer);


    //for text
    bool addText(std::string id,std::string textureText, SDL_Color textColor);
    bool setFont(uint16_t  size = 12,std::string font_path = MainWindowSetting::GetFontPath());
    void viewText(std::string id,int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

};


#endif //TEMPLATE_TEXTUREFACTORY_H
