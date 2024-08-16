//
// Created by duong on 8/16/24.
//

#ifndef TEMPLATE_TEXT_H
#define TEMPLATE_TEXT_H


#include "config.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class Text
{
public:
    //Initializes variables
    Text(uint16_t  size = 12,std::string font_path = std::string(_materials)+"Myfont.ttf");

    //Deallocates memory
    ~Text();

    //Loads image at specified path
    bool loadFromFile( std::string path );

    //Creates image from font string
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    //Set blending
    void setBlendMode( SDL_BlendMode blending );

    //Set alpha modulation
    void setAlpha( Uint8 alpha );

    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    //Set renderer
    void setRenderer(SDL_Renderer* renderer){gRenderer = renderer;}

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;
    SDL_Renderer* gRenderer{NULL};
    TTF_Font* gFont {NULL};

};


#endif //TEMPLATE_TEXT_H
