//
// Created by duong on 8/20/24.
//

#ifndef TEMPLATE_OBSERVERPATTERN_H
#define TEMPLATE_OBSERVERPATTERN_H


#include <any>
#include <iostream>
#include <list>
using std::string;
using std::list;
using std::any;


class Observer
{
public:
    virtual ~Observer(){};
    virtual void Update(any event) = 0;
};

class Subject {
public:
    virtual ~Subject(){};
    void Attach(Observer *observer)  {
        mObservers.push_back(observer);
    }
    void Detach(Observer *observer)  {
        mObservers.remove(observer);
    }
    void Notify(){
        std::list<Observer *>::iterator iterator = mObservers.begin();
        while (iterator != mObservers.end()) {
            (*iterator)->Update(mEvent);
            ++iterator;
        }
    }

protected:
    list<Observer *> mObservers;
    any mEvent;
};


#endif //TEMPLATE_OBSERVERPATTERN_H
