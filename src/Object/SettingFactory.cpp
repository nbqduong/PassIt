//
// Created by duong on 8/18/24.
//

#include "SettingFactory.h"
#include <iostream>


const vector<shared_ptr<TextObject>>&SettingFactory::CreateSettings()
{
    //Create header
    mTexts.push_back(TextFactory::GetInstance().CreateTitle(mName));

    //Create options
    for(auto a : mOptions)
    {
        auto tmp_opt{ TextFactory::GetInstance().CreateOption(a.name,a.options.at(a.current))};
        mTexts.insert(mTexts.end(),tmp_opt.begin(), tmp_opt.end());
    }
    mMaxSetting = static_cast<int>(mOptions.size());

    //Change visual of curren setting
    mTexts.at((mCurrentSetting+1)*2)->Resize(30);
    return mTexts;
}

void SettingFactory::RegisterOption(std::string title, vector<std::string> _options)
{
    mOptions.push_back(OptionInfo(title,_options));
}

void SettingFactory::SwitchOption(const UserEvent &direction)
{
    try{
        //Current setting is setting at
        //map with text follow equation: text = (setting+1)*2

        auto& current_option = mOptions.at(mCurrentSetting);
        current_option.Switch(direction);
        mTexts.at((mCurrentSetting+1)*2)->ChangeContent(current_option.options.at(current_option.current));
    }catch (const std::out_of_range& e) {
        std::cerr << "[Exception] Switching option error: } " << e.what() << std::endl;
    }

}

void SettingFactory::SwitchSetting(const UserEvent &direction)
{
    //old setting change to normal size
    mTexts.at((mCurrentSetting+1)*2)->Resize(20);

    if(direction == UserEvent::emUp)
    {
        //mCurrenSetting point to current setting
        mCurrentSetting =  --mCurrentSetting >= 0 ? mCurrentSetting : mMaxSetting-1;
    }
    else
    {
        mCurrentSetting =  ++mCurrentSetting < mMaxSetting ? mCurrentSetting : 0;
    }
    //Change visual of curren setting
    mTexts.at((mCurrentSetting+1)*2)->Resize(30);
}

int SettingFactory::DirectionConverter(const UserEvent &direction)
{
    int &max = mOptions.at(mCurrentSetting).max,
        &current = mOptions.at(mCurrentSetting).current;

    if(direction == UserEvent::emLeft)
    {
        return --current >= 0 ? current : max-1;
    }
    return ++current < max ? current : 0;
}