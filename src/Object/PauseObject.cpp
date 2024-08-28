//
// Created by duong on 28/08/2024.
//

#include "PauseObject.h"

#include "TextFactory.h"

PauseObject::PauseObject() {
    auto &factory = TextFactory::GetInstance();

    //Window title is pause
    mTexts.push_back(factory.CreateTitle("Paused"));

    //Get texts
    auto texts = MainWindowSetting::GetPasue();

    //Create Pause content from row 3
    uint16_t row = 3, column = 2;
    for (auto &text : texts) {
        mTexts.push_back(factory.CreateText(text, {column, row}));
        row +=2;
    }

}
