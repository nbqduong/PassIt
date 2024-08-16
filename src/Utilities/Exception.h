//
// Created by duong on 8/16/24.
//

#ifndef TEMPLATE_EXCEPTION_H
#define TEMPLATE_EXCEPTION_H
#include <string>
#include <string_view>



using std::string;
using std::string_view;

class Exception
{
public:
    explicit Exception(string_view msg) : mMsg{std::string(msg) + "\n"} { }
    const string& what() const { return mMsg; }

private:
    string mMsg;
};


#endif //TEMPLATE_EXCEPTION_H
