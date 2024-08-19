//
// Created by duong on 8/17/24.
//

#ifndef TEMPLATE_TEXTOBJECT_H
#define TEMPLATE_TEXTOBJECT_H


#include "Setting.h"
#include <SDL_pixels.h>
#include <cstdint>
#include <string>

using std::string;

struct TextInfo{
    Co pos;
    uint16_t size;
    std::string  ID, font, content;
    SDL_Color color;

    TextInfo(const Co& _pos, const uint16_t& _size, const std::string _ID, const std::string _content, const std::string _font, SDL_Color _color)
        :pos{_pos},size{_size}, ID{_ID}, font{_font}, content{_content}, color{_color}
    {}
};

class TextObject
{
protected:
    TextInfo mInfo;
public:
    TextObject() = delete;
    TextObject(const Co& _pos, const uint16_t& _size, const std::string _ID, const std::string _content, const std::string _font = MainWindowSetting::GetFontPath(), SDL_Color _color={0,0,0})
        :mInfo{_pos, _size, _ID, _content, _font, _color}
    {
    }
    const TextInfo& GetInfo() const {return mInfo;}
    void ChangeContent(string _content){mInfo.content = _content;}
    void Resize(int _size){mInfo.size = _size; }
    ~TextObject()=default;
};


#endif //TEMPLATE_TEXTOBJECT_H
