//
// Created by duong on 29/08/2024.
//

#ifndef ENDOBJECT_H
#define ENDOBJECT_H
#include <memory>
#include <vector>
#include "TextObject.h"

class EndObject {
public:
    static EndObject &GetInstance(){static EndObject mInstance; return mInstance; }
    std::vector<std::shared_ptr<TextObject>> GetTextObject(){return mTexts;};

private:
    EndObject();
    std::vector<std::shared_ptr<TextObject>> mTexts;
    std::vector<std::string> mContents =
        {"Congratulation for finish scratch version of "+std::string(project_name),
        "To taste it again press T",
        "To return main setting press SPACE",
        "To exit press ESC"};
};



#endif //ENDOBJECT_H
