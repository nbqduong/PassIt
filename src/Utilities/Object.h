//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_OBJECT_H
#define TEMPLATE_OBJECT_H

//#include <cstdint>
//#include <string>
//
//enum class TouchEvent {
//    emBlock,
//    emPass,
//};
//
//struct ObjInfo{
//    XYWH mView, mSource;
//    std::string mDrawID, mID, mFileName;
//
//};
//class Object {
//protected:
//    ObjInfo mInfo;
//
//public:
//    Object() = delete;
//    Object(const char* link, const std::string &m_id, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
//    {
//        mInfo.mFileName = link;
//        mInfo.mDrawID= m_id;
//        mInfo.mView= GamePosition::Get(x,y,width, height);
//    }
//
//    const ObjInfo * GetInfo() const {return &mInfo;}
//    void Resize(uint32_t width, uint32_t height);
//    virtual TouchEvent Touched(){};
//    virtual ~Object()=default;
//};

#endif //TEMPLATE_OBJECT_H
