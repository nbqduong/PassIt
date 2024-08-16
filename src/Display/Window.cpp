//
// Created by duong on 8/15/24.
//

#include "Window.h"
#include "Text.h"
#include "TextureFactory.h"
Windows::Windows(std::string_view windows_name, uint16_t size_PX, uint16_t size_PY,uint16_t pos_PX, uint16_t pos_PY)
    : mName{windows_name},mWidth{size_PX}, mHeight{size_PY}
{
//    Create window
    mWindow = SDL_CreateWindow( mName.c_str(), pos_PX, pos_PY, mWidth, mHeight, SDL_WINDOW_SHOWN );
    if( mWindow == nullptr )
    {
        throw Exception{"Window could not be created!" + std::string(SDL_GetError())};
    }
    //Get window surface
    mRenderer = SDL_CreateRenderer( mWindow ,-1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if( mRenderer == nullptr )
    {
        SDL_DestroyWindow( mWindow );
        throw Exception{"Could not get window renderer!" + std::string(SDL_GetError())};
    }

    mTexture.setRenderer(mRenderer);
    mText.setRenderer(mRenderer);
}

Windows::~Windows() {
    SDL_Log("~Windows destructor");
    //Destroy Renderer
    SDL_DestroyRenderer(mRenderer);
    SDL_Log("Destroy renderer");
    //Destroy window
    SDL_DestroyWindow( mWindow );
    SDL_Log("Destroy Window");
}


void Windows::Render() {
    //Render text
    if( !mTexture.addText( "test","The quick brown fox jumps over the lazy dog", { 0, 0, 0 } ) )
    {
        printf( "Failed to render text texture!\n" );
    }

    SDL_SetRenderDrawColor(mRenderer, 193, 224, 245,255);
    SDL_RenderClear(mRenderer);

//    TextureManager::GetInstance()->Show();
    mTexture.viewText("test",0,0);

//    TextureFactory::GetInstance().DrawFrame("tree", {0,0},{640,640},{100,100},{640,640});
    SDL_RenderPresent(mRenderer);
}


void SettingWindow::Render()
{
    //Render text
    if( !mText.loadFromRenderedText( "The quick brown fox jumps over the lazy dog", { 0, 0, 0 } ) )
    {
        printf( "Failed to render text texture!\n" );
    }

    SDL_SetRenderDrawColor(mRenderer, 193, 224, 245,255);
    SDL_RenderClear(mRenderer);

    //    TextureManager::GetInstance()->Show();
    mText.render(0,0);
    mText.render(0,100);

    //    TextureFactory::GetInstance().DrawFrame("tree", {0,0},{640,640},{100,100},{640,640});
    SDL_RenderPresent(mRenderer);
}

