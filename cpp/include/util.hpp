#pragma once

#include <iostream>
#include <cstring>

class Util {
public:
    virtual void setChapter(const std::string chapter);
    static void setBigTitle(const std::string title) {
        std::cout << std::endl << std::endl << " ## " << title << " ## " << std::endl << std::endl;
    }
    virtual void setSubTitle(const std::string subtitle);
};
