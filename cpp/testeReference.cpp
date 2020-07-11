#include <iostream>
#include <cstring>
#include <stdio.h>

int main()
{
    std::string a = "hello";
    std::string b = "yay!";
    std::string &c = a;
    std::string &d = b;

    std::cout << a << std::endl << b << std::endl << c << std::endl << d << std::endl;
    printf("a: %p\n", &a);
    printf("c: %p %p\n", b, &b);
    printf("d: %p %p\n", c, &c);








}
