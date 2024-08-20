//
// Created by duong on 8/18/24.
//

#ifndef TEMPLATE_SETTINGFACTORY_H
#define TEMPLATE_SETTINGFACTORY_H

#include "TextObject.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include "TextFactory.h"



using std::unordered_map;
using std::string;
using std::vector;
using std::shared_ptr;



class SettingFactory
{
protected:
    int mCurrentSetting{0}, mMaxSetting;
    vector<OptionInfo> mOptions;
    vector<shared_ptr<TextObject>> mTexts;
    string mName;

    //convert direction to option index of current setting
    int DirectionConverter(const UserEvent &direction);

    SettingFactory(string name):mName{name}{}

    //register options
    void RegisterOption(string title, vector<string> _options);

    //Create setting backend
    const vector<shared_ptr<TextObject>>& CreateSettings();

    //Switch option
    void SwitchOption(const UserEvent &direction);


    //Switch setting
    void SwitchSetting(const UserEvent &direction);

public:
    //Get current setting
    const vector<shared_ptr<TextObject>> GetCurrentSettingText(){return mTexts;}
    vector<OptionInfo> &GetCurrentOption() {return mOptions;}
};


#endif //TEMPLATE_SETTINGFACTORY_H
