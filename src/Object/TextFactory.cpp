//
// Created by duong on 8/17/24.
//

#include "TextFactory.h"
#include <SDL_log.h>
uint16_t TextFactory::mID = 0;

std::shared_ptr<TextObject> TextFactory::CreateTitle(const std::string text)
{
    return std::make_shared<TextObject>(Convert::toPx(3,1),40,std::to_string(mID++)+"_Header",text);
}
TextFactory::~TextFactory()
{
    SDL_Log("~TextFactory destructor");
}

// std::vector<std::shared_ptr<TextObject>> TextFactory::CreateSettingWindow()
// {
//     std::vector<std::shared_ptr<TextObject>> tmp {TextFactory::GetInstance().CreateTitle("PassIt Setting")};
//
//     vector<shared_ptr<TextObject>>  option1 = CreateOption("a", "test");
//
//     tmp.insert(tmp.end(), option1.begin(), option1.end());
//
// //    tmp.push_back(TextFactory::GetInstance().CreateTitle("PassIt Setting"));
//
//     return tmp;
// }

vector<shared_ptr<TextObject>> TextFactory::CreateOption(const string name , const string opt)
{
    //start first option from row 3
    static int Y = 3;

    //create option object from column 1, row Y  ------------ selection at column 8
    vector<shared_ptr<TextObject>> tmp = {make_shared<TextObject>(Convert::toPx(1,Y),20,std::to_string(mID++)+"_option", name)};
    tmp.push_back(make_shared<TextObject>(Convert::toPx(8,Y),20,std::to_string(mID++)+"_option", opt));

    //Increase for next option
    Y +=2;

    //return option
    return tmp;
}

shared_ptr<TextObject> TextFactory::CreateText(const string name, Co pos) {
    return make_shared<TextObject>(Convert::toPx(pos.X,pos.Y),20,std::to_string(mID++)+"note", name);
}
