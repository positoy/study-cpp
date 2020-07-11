#include <iostream>
int main()
{
    int a,b;
    std::cin >> a >> b;
    //if (b<=0) return 1;
    try
    {
        if (b<=0) throw b;
        std::cout << a/b << std::endl;
    }
    catch(int exception)
    {
        std::cout << "divider less euqal than zero: " << exception << std::endl;
    }
}
