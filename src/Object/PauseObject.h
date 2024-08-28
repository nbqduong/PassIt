//
// Created by duong on 28/08/2024.
//

#ifndef PAUSEOBJECT_H
#define PAUSEOBJECT_H
#include <memory>
#include <vector>
#include "TextObject.h"

using std::vector;

class PauseObject {
public:
    static PauseObject &GetInstance(){static PauseObject mInstance; return mInstance; }
    vector<std::shared_ptr<TextObject>> GetPauseText(){return mTexts;};

private:
    PauseObject();
    vector<std::shared_ptr<TextObject>> mTexts;
};



#endif //PAUSEOBJECT_H
