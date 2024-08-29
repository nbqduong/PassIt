//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_OBJECT_H
#define TEMPLATE_OBJECT_H

#include <cstdint>
#include <string>
#include <Setting.h>

#include "ObserverPattern.h"

enum class TouchEvent {
    emBlock,
    emPass,
};

struct ObjInfo{
    Co mView, mSource;
    std::string mDrawID, mID, mFileName;

};
class Object: public Subject{
protected:
    ObjInfo mInfo;

public:
    Object() = delete;
    Object(const string link, const std::string &m_id, Co view_pos)
    {
        mInfo.mFileName = link;
        mInfo.mDrawID= m_id;
        mInfo.mView= view_pos;
    }

    ObjInfo& GetInfo() {return mInfo;}
    void Resize(uint32_t width, uint32_t height);
    virtual TouchEvent Touched(){};
    virtual ~Object()=default;
};

#endif //TEMPLATE_OBJECT_H
