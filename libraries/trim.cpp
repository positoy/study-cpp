#include <iostream>
#include <string>
#include <algorithm>

static inline std::string ltrim(std::string str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](char ch){
        return !std::isspace(ch);
    }));
    return str;
}

static inline std::string rtrim(std::string str) {
    str.erase(std::find_if(str.rbegin(), str.rend(), [](char ch){
        return !std::isspace(ch);
    }).base(), str.end());
    return str;
}

static inline std::string trim(std::string str) {
    return rtrim(ltrim(str));
}

int main()
{
    std::string lspace, rspace, space;
    lspace = rspace = space = "  \t   firstword  \t   secondword    \t   ";

    std::cout << '[' << ltrim(lspace) << ']' << std::endl;
    std::cout << '[' << rtrim(rspace) << ']' << std::endl;
    std::cout << '[' << trim(space) << ']' << std::endl;
    
}