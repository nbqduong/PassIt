#include "Engine.h"
#include "config.hpp"
#include <Input.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <filesystem>
#include <fstream>
#include <iostream>


int main( int argc, char* args[] )
{
    // int * a = new int;
    try{
        Engine::GetInstance().Start();

    }catch(const Exception &exception)
    {
        std::cerr << "Exception: " << exception.what() << std::endl;
    }

    return 0;
}