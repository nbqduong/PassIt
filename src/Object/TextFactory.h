//
// Created by duong on 8/17/24.
//

#ifndef TEMPLATE_TEXTFACTORY_H
#define TEMPLATE_TEXTFACTORY_H
#include "TextObject.h"
#include <memory>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::string;
using std::vector;
using std::shared_ptr;

class TextFactory
{

    TextFactory(){};
    static uint16_t mID;

public:
    static TextFactory& GetInstance(){static TextFactory mInstance; return mInstance;}

    //Create windows title
    shared_ptr<TextObject> CreateTitle(const string text);

    //Create setting options
    vector<shared_ptr<TextObject>> CreateOption(const string name , const string opt);

    //Create normal text


    //Create small text for noting

    //Create setting windows
    std::vector<std::shared_ptr<TextObject>> CreateSettingWindow();

    virtual ~TextFactory();
};


#endif //TEMPLATE_TEXTFACTORY_H
