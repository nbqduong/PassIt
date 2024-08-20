//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_MAP_H
#define TEMPLATE_MAP_H
#include <memory>
#include "Setting.h"

class Map {
//    const uint16_t mWidth{MAX_X}, mHeight{MAX_Y};
    /*
     * ----------Map Define elements----------------
     *      Symbol             Meaning
     *        0                 tile
     *        1                 wall
     *        2                 bush
     *        3                 rock
     *        4                 chest
     *        5                 snake
     *        6                 gate
     *        7                 water
     *
     *----------------------------------------------*/
    uint8_t mStructure[MAX_Y][MAX_X] {

        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,3,1},
        {1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,2,2,2,2,1},
        {1,2,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,3,3,1,0,1},
        {1,0,3,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,2,2,2,0,0,1},
        {1,4,1,5,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,3,2,2,1,4,1},
        {1,1,1,2,2,2,2,2,2,2,2,0,0,1,1,0,0,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,1},
        {1,3,3,3,3,3,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,1},
        {1,2,2,2,2,2,3,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,1},
        {1,2,0,0,2,3,3,3,3,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,1},
        {1,2,3,3,3,4,2,2,2,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,1},
        {0,2,2,2,2,3,2,2,2,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };

    Map(){};
public:
    static Map& GetInstance(){ static Map mInstance; return mInstance;}
    void Create();
    static uint8_t GetWidth(){return MAX_X;}
    static uint8_t GetHeight(){return MAX_Y;}
    uint8_t GetObject(uint8_t row, uint8_t collum){return mStructure[row][collum];}
    uint16_t GetVectorIndex(uint8_t row, uint8_t collum){return row*MAX_Y+collum;}
    uint16_t GetSize(){return MAX_X*MAX_Y;};

private:

};


//static const uint16_t Map::mWidth = MAX_X;
//const uint16_t Map::mHeight = MAX_Y;
#endif //TEMPLATE_MAP_H
