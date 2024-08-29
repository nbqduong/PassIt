//
// Created by duong on 29/08/2024.
//

#ifndef SCORE_H
#define SCORE_H
#include <cstdint>


class Score {
public:
    static Score&   GetInstance() {static Score mInsance; return mInsance;}
    void            CollectKey(){mKey++;}
    uint32_t        GetKey(){return mKey;};
    bool            IsCollectAllKey(){return mKey==mMaxKey;}
    void            Reset(){mKey = 0;}
private:
    Score() {};
    uint16_t mKey{0}, mMaxKey{3};
};



#endif //SCORE_H
