//
// Created by duong on 29/08/2024.
//

#include "EndObject.h"

#include "TextFactory.h"

EndObject::EndObject() {
    auto &factory = TextFactory::GetInstance();

    //Window title is pause
    mTexts.push_back(factory.CreateTitle("Paused"));

    //Create Pause content from row 3
    uint16_t row = 3, column = 2;
    for (auto &text : mContents) {
        mTexts.push_back(factory.CreateText(text, {column, row}));
        row +=1;
    }
}
