//
// Created by duong on 8/16/24.
//

#include "TextureFactory.h"
#include "Exception.h"

TextureFactory::TextureFactory(uint16_t  text_size ,std::string font_path )
{
    //Open the font
    gFont = TTF_OpenFont( font_path.c_str(), text_size );
    if( gFont == NULL )
    {
        throw Exception{"Failed to load lazy font! SDL_ttf Error:" + std::string(TTF_GetError()) };

    }
}

bool TextureFactory::Load(std::string id, std::string filename){

    //if id existed, destroy it first
    auto it_texture = mTextureMap.find(id);
    if (it_texture != mTextureMap.end())
    {
        Drop(id);
    }

    SDL_Surface* surface = IMG_Load(filename.c_str());
    if(surface == nullptr){
        SDL_Log("Failed to load texture: %s, %s", filename.c_str(), SDL_GetError());
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, surface);
    if(texture == nullptr){
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
        return false;
    }

    mTextureMap[id] = texture;
    return true;
}
void TextureFactory::Drop(std::string id){
    SDL_DestroyTexture(mTextureMap[id]);
    mTextureMap.erase(id);
}
void TextureFactory::Clean(){
    std::map<std::string, SDL_Texture*>::iterator it;
    for(it = mTextureMap.begin(); it != mTextureMap.end(); it++)
        SDL_DestroyTexture(it->second);

    mTextureMap.clear();
    mTextSie.clear();

    SDL_Log("Texture map cleaned!");
}

void TextureFactory::DrawFrame(std::string id, Co src_pos, Co src_range, Co dst_pos, Co dst_range, SDL_RendererFlip flip) const
{
    SDL_Rect srcRect = {src_pos.X, src_pos.Y, src_range.X, src_range.Y};
    SDL_Rect dstRect = {dst_pos.X, dst_pos.Y, dst_range.X, dst_range.Y};
    // Use find to get a const iterator
    auto it = mTextureMap.find(id);

    // Check if texture is found
    if (it != mTextureMap.end()) {
        SDL_Texture* texture = it->second; // Get the texture

        // Call SDL_RenderCopyEx
        SDL_RenderCopyEx(mRenderer, texture, &srcRect, &dstRect, 0, nullptr, flip);
    } else {
        // Handle the case where the texture is not found
        // Optionally log an error or take corrective action
        SDL_Log("[TextureFactory] Could not found ", id.c_str());
    }
}
void TextureFactory::setRenderer(SDL_Renderer* renderer){
    this->mRenderer = renderer;
}
TextureFactory::~TextureFactory(){
    Clean();
    SDL_Log("~TextureFactory destructor");
}

bool TextureFactory::addText(std::string id, std::string textureText, SDL_Color textColor)
{
    std::string text_id = "text_"+id;

    //if id existed, destroy it first
    auto it_texture = mTextureMap.find(text_id);
    if (it_texture != mTextureMap.end())
    {
        Drop(text_id);
    }

    SDL_Texture* mTexture  = nullptr;
        //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( mRenderer, textSurface );
        if( mTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mTextSie[text_id] = {static_cast<uint16_t >(textSurface->w),static_cast<uint16_t >(textSurface->h)};
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    mTextureMap[text_id] = mTexture;
    //Return success
    return mTexture != NULL;
}

bool TextureFactory::setFont(uint16_t size, std::string font_path)
{
    //Open the font
    gFont = TTF_OpenFont( font_path.c_str(), size );
    if( gFont == NULL )
    {
        throw Exception{"Failed to load lazy font! SDL_ttf Error:" + std::string(TTF_GetError()) };

    }
}

void TextureFactory::viewText(std::string id,int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip)
{
    std::string text_id = "text_"+id;
    // Use find to get a const iterator
    auto it_texture = mTextureMap.find(text_id);
    auto it_size = mTextSie.find(text_id);

    // Check if texture is found
    if (it_texture != mTextureMap.end() && it_size != mTextSie.end()) {
        //Set rendering space and render to screen
        SDL_Rect renderQuad = { x, y, it_size->second.X, it_size->second.Y };

        //Set clip rendering dimensions
        if( clip != NULL )
        {
            renderQuad.w = clip->w;
            renderQuad.h = clip->h;
        }

        SDL_Texture* texture = it_texture->second; // Get the texture

        // Call SDL_RenderCopyEx
        SDL_RenderCopyEx(mRenderer, texture, clip, &renderQuad, angle, center, flip);
    } else {
        // Handle the case where the texture is not found
        // Optionally log an error or take corrective action
        SDL_Log("[TextureFactory] Could not found ", text_id.c_str());
    }
}

